/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 19:02:36 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "cd") == 0
		|| strcmp(cmd, "pwd") == 0 || strcmp(cmd, "export") == 0
		|| strcmp(cmd, "unset") == 0 || strcmp(cmd, "env") == 0
		|| strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	execute_builtin_with_cmd(t_shell_line *cmd_node, t_data *d)
{
	if (!cmd_node || !cmd_node->cmd || !cmd_node->cmd[0])
		return (1);
	d->exit_status = 0;
	if (strcmp(cmd_node->cmd[0], "echo") == 0)
	{
		echo(cmd_node->cmd);
		return (d->exit_status);
	}
	else if (strcmp(cmd_node->cmd[0], "cd") == 0)
		cd(d);
	else if (strcmp(cmd_node->cmd[0], "pwd") == 0)
		pwd();
	else if (strcmp(cmd_node->cmd[0], "export") == 0)
		export(d);
	else if (strcmp(cmd_node->cmd[0], "unset") == 0)
		unset(d);
	else if (strcmp(cmd_node->cmd[0], "env") == 0)
		env(d);
	else if (strcmp(cmd_node->cmd[0], "exit") == 0)
		exit_shell(d);
	else
		return (127);
	return (d->exit_status);
}

int	execute_builtin(t_data *d)
{
	t_shell_line	*current_cmd;

	if (d->pipeline.current_cmd)
		current_cmd = d->pipeline.current_cmd;
	else
		current_cmd = d->sh_ln;
	return (execute_builtin_with_cmd(current_cmd, d));
}
