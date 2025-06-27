/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:18:32 by aternero          #+#    #+#             */
/*   Updated: 2025/06/21 22:10:52 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	validate_redirections(t_shell_line *cmd_node)
{
	t_redirect	*redir;
	int			fd;

	redir = cmd_node->redir;
	while (redir)
	{
		if (ft_strcmp(redir->type, "<") == 0)
		{
			fd = open(redir->file, O_RDONLY);
			if (fd == -1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(redir->file, 2);
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(strerror(errno), 2);
				ft_putstr_fd("\n", 2);
				return (-1);
			}
			close(fd);
		}
		redir = redir->next;
	}
	return (0);
}

pid_t	fork_process(t_data *d)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid == -1)
	{
		if (!d->pipeline.is_last)
		{
			close(d->pipeline.pipefd[0]);
			close(d->pipeline.pipefd[1]);
		}
		if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
			close(d->pipeline.prev_pipe_read_end);
		i = d->pipeline.cmd_index;
		while (--i >= 0)
			waitpid(d->pipeline.pids[i], NULL, 0);
		free(d->pipeline.pids);
		custom_exit(d, "fork failed", EXIT_FAILURE);
	}
	return (pid);
}
