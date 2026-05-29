/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent_builtins.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_parent_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "export") == 0
		|| strcmp(cmd, "unset") == 0 || strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	handle_single_parent_buildin(t_data *d)
{
	if (d->pipeline.cmd_count == 1 && is_parent_builtin(d->sh_ln->cmd[0]))
	{
		d->exit_status = execute_builtin(d);
		return (1);
	}
	return (0);
}
