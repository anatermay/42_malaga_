/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exec_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_cmd_not_found(t_shell_line *cmd_node)
{
	int	cmd_status;

	if (ft_strchr(cmd_node->cmd[0], '/'))
	{
		cmd_status = handle_file_execution(cmd_node->cmd[0], cmd_node->cmd);
		exit(cmd_status);
	}
	print_command_not_found(cmd_node->cmd[0]);
	exit(127);
}

static void	execute_cmd_with_path(char *cmd_path, t_shell_line *cmd_node,
	t_data *d)
{
	int	cmd_status;

	cmd_status = handle_file_execution(cmd_path, cmd_node->cmd);
	if (cmd_status != 0)
	{
		free(cmd_path);
		exit(cmd_status);
	}
	if (execve(cmd_path, cmd_node->cmd, d->str_env) == -1)
	{
		print_exec_error(cmd_path, strerror(errno));
		free(cmd_path);
		exit(126);
	}
	free(cmd_path);
	exit(EXIT_FAILURE);
}

void	execute_external_command(t_shell_line *cmd_node, t_data *d)
{
	char	*cmd_path;

	cmd_path = find_cmd_path_in_exec(cmd_node->cmd[0], d);
	if (!cmd_path)
		handle_cmd_not_found(cmd_node);
	execute_cmd_with_path(cmd_path, cmd_node, d);
}
