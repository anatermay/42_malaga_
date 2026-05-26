/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	count_commands(t_data *d)
{
	t_shell_line	*temp;

	d->pipeline.cmd_count = 0;
	temp = d->sh_ln;
	while (temp)
	{
		d->pipeline.cmd_count++;
		temp = temp->next;
	}
}

static int	validate_pipeline_syntax(t_data *d)
{
	t_shell_line	*temp;
	int				pipe_count;
	char			*error_msg;

	error_msg = "minishell: syntax error near unexpected token `|'\n";
	temp = d->sh_ln;
	pipe_count = 0;
	while (temp)
	{
		if (!temp->cmd || !temp->cmd[0] || temp->cmd[0][0] == '\0')
		{
			if (temp->next || pipe_count > 0)
			{
				ft_putstr_fd(error_msg, 2);
				d->exit_status = 2;
				return (0);
			}
		}
		if (temp->next)
			pipe_count++;
		temp = temp->next;
	}
	return (1);
}

static int	process_all_heredocs(t_data *d)
{
	t_shell_line	*current_cmd;
	t_redirect		*redir;

	current_cmd = d->sh_ln;
	while (current_cmd)
	{
		redir = current_cmd->redir;
		while (redir)
		{
			if (ft_strcmp(redir->type, "<<") == 0)
			{
				if (process_heredoc(redir, d) == -1)
					return (-1);
			}
			redir = redir->next;
		}
		current_cmd = current_cmd->next;
	}
	return (0);
}

static int	execute_pipeline_setup(t_data *d)
{
	if (process_all_heredocs(d) == -1)
	{
		d->exit_status = 1;
		return (-1);
	}
	if (handle_single_parent_buildin(d) == 1)
		return (1);
	d->pipeline.pids = malloc(d->pipeline.cmd_count * sizeof(pid_t));
	if (!d->pipeline.pids)
		custom_exit(d, "malloc pids failed", EXIT_FAILURE);
	return (0);
}

void	executer(t_data *d)
{
	int	pipeline_result;
	int	setup_result;

	if (!d->sh_ln || !d->sh_ln->cmd || !d->sh_ln->cmd[0])
		return ;
	count_commands(d);
	if (!validate_pipeline_syntax(d))
		return ;
	setup_result = execute_pipeline_setup(d);
	if (setup_result == -1 || setup_result == 1)
		return ;
	g_signal = S_CMD;
	pipeline_result = execute_pipeline(d);
	if (pipeline_result == 0)
	{
		d->exit_status = 0;
		wait_for_children(d);
	}
	g_signal = S_BASE;
	free(d->pipeline.pids);
}
