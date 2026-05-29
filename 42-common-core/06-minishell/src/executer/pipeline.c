/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 17:44:13 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_pipe_failure(t_data *d)
{
	free(d->pipeline.pids);
	if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
		close(d->pipeline.prev_pipe_read_end);
	custom_exit(d, "pipe failed", EXIT_FAILURE);
}

void	create_pipe_if_needed(t_data *d)
{
	d->pipeline.current_pipe_write_end = STDOUT_FILENO;
	if (!d->pipeline.is_last)
	{
		if (pipe(d->pipeline.pipefd) == -1)
			handle_pipe_failure(d);
		d->pipeline.current_pipe_write_end = d->pipeline.pipefd[1];
	}
}

static int	validate_single_command(t_data *d)
{
	if (d->pipeline.cmd_count == 1
		&& validate_redirections(d->pipeline.current_cmd) == -1)
	{
		d->exit_status = 1;
		return (-1);
	}
	return (0);
}

void	execute_pipeline_2(pid_t pid, t_data *d)
{
	if (pid == 0)
	{
		setup_child_redirections(d);
		execute_child_command(d->pipeline.current_cmd, d);
	}
	else
	{
		d->pipeline.pids[d->pipeline.cmd_index] = pid;
		handle_parent_pipes(d);
	}
}

int	execute_pipeline(t_data *d)
{
	pid_t	pid;

	d->pipeline.cmd_index = 0;
	d->pipeline.prev_pipe_read_end = STDIN_FILENO;
	d->pipeline.current_cmd = d->sh_ln;
	while (d->pipeline.current_cmd)
	{
		d->pipeline.is_last = (d->pipeline.current_cmd->next == NULL);
		create_pipe_if_needed(d);
		if (validate_single_command(d) == -1)
			return (-1);
		pid = fork_process(d);
		execute_pipeline_2(pid, d);
		d->pipeline.current_cmd = d->pipeline.current_cmd->next;
		d->pipeline.cmd_index++;
	}
	return (0);
}
