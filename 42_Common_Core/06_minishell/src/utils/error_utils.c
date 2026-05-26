/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 19:54:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_minishell_error(char *cmd, char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (cmd)
		ft_putstr_fd(cmd, 2);
	ft_putstr_fd(error_msg, 2);
}

void	print_command_not_found(char *cmd)
{
	print_minishell_error(cmd, ": command not found\n");
}

void	print_no_such_file(char *cmd)
{
	print_minishell_error(cmd, ": No such file or directory\n");
}

void	print_is_directory(char *cmd)
{
	print_minishell_error(cmd, ": Is a directory\n");
}

void	print_permission_denied(char *cmd)
{
	print_minishell_error(cmd, ": Permission denied\n");
}
