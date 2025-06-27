/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:37:01 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 20:37:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cleanup_resources(t_temp_redir *redir, t_shell_line *command,
		char **temp, int free_cmd)
{
	if (redir->without_redir && redir->without_redir != redir->line)
		free(redir->without_redir);
	free(redir);
	if (free_cmd)
		free(command->cmd);
	free(command->line);
	array_free(temp);
	free(command);
}

int	handle_special_var(t_shell_line *command, int yndex)
{
	if (yndex == 0 && command->cmd[yndex] && command->cmd[yndex][0] == '\x01'
		&& command->cmd[yndex][1] == '\0')
	{
		command->empty_quoted_var = 1;
		free(command->cmd[yndex]);
		command->cmd[yndex] = ft_strdup("");
		if (!command->cmd[yndex])
			return (-1);
	}
	return (0);
}
