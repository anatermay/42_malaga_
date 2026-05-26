/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:56:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	setup_child_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_dollar_command(t_shell_line *cmd_node)
{
	if (cmd_node->cmd[0] && ft_strcmp(cmd_node->cmd[0], "$") == 0)
	{
		print_minishell_error("$", ": command not found\n");
		exit(127);
	}
}

void	handle_empty_command(t_shell_line *cmd_node)
{
	int	i;

	if (cmd_node->cmd[0] && cmd_node->cmd[0][0] == '\0' && cmd_node->cmd[1])
	{
		free(cmd_node->cmd[0]);
		i = 0;
		while (cmd_node->cmd[i + 1])
		{
			cmd_node->cmd[i] = cmd_node->cmd[i + 1];
			i++;
		}
		cmd_node->cmd[i] = NULL;
	}
	if (!cmd_node->cmd[0] || cmd_node->cmd[0][0] == '\0')
	{
		if (cmd_node->empty_quoted_var)
		{
			print_minishell_error("", ": command not found\n");
			exit(127);
		}
		exit(0);
	}
}

int	handle_file_execution(char *cmd_path, char **args)
{
	struct stat	file_stat;

	if (access(cmd_path, F_OK) != 0)
	{
		print_no_such_file(args[0]);
		return (127);
	}
	if (stat(cmd_path, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
	{
		print_is_directory(args[0]);
		return (126);
	}
	if (access(cmd_path, X_OK) != 0)
	{
		print_permission_denied(args[0]);
		return (126);
	}
	return (0);
}
