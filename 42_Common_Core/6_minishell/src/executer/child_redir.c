/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 13:46:13 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	apply_redirections(t_shell_line *cmd_node, t_data *d)
{
	t_redirect	*redir;

	if (validate_input_files(cmd_node) == -1)
		return (-1);
	redir = cmd_node->redir;
	while (redir)
	{
		if (ft_strchr(redir->type, '>'))
		{
			if (handle_output_redirect(redir) == -1)
				return (-1);
		}
		else if (ft_strchr(redir->type, '<'))
		{
			if (handle_input_redirect(redir, d) == -1)
				return (-1);
		}
		redir = redir->next;
	}
	return (0);
}

void	setup_stdin_redirection(t_data *d)
{
	if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
	{
		if (dup2(d->pipeline.prev_pipe_read_end, STDIN_FILENO) == -1)
		{
			ft_putstr_fd("minishell: dup2 stdin: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			exit(EXIT_FAILURE);
		}
		close(d->pipeline.prev_pipe_read_end);
	}
}

void	setup_stdout_redirection(t_data *d)
{
	if (d->pipeline.current_pipe_write_end != STDOUT_FILENO)
	{
		if (dup2(d->pipeline.current_pipe_write_end, STDOUT_FILENO) == -1)
		{
			ft_putstr_fd("minishell: dup2 stdout: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			exit(EXIT_FAILURE);
		}
		close(d->pipeline.current_pipe_write_end);
	}
}

void	setup_child_redirections(t_data *d)
{
	int	next_pipe_read_end;

	if (!d->pipeline.is_last)
	{
		next_pipe_read_end = d->pipeline.pipefd[0];
		close(next_pipe_read_end);
	}
	setup_stdin_redirection(d);
	setup_stdout_redirection(d);
	if (apply_redirections(d->pipeline.current_cmd, d) == -1)
		exit(EXIT_FAILURE);
}
