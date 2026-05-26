/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 15:52:17 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_child_command(t_shell_line *cmd_node, t_data *d)
{
	int	builtin_exit_code;

	setup_child_signals();
	handle_dollar_command(cmd_node);
	handle_empty_command(cmd_node);
	if (is_builtin(cmd_node->cmd[0]))
	{
		builtin_exit_code = execute_builtin_with_cmd(cmd_node, d);
		exit(builtin_exit_code);
	}
	execute_external_command(cmd_node, d);
}
