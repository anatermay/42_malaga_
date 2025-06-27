/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_command_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:19:54 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 16:38:11 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	process_cmd_args(t_shell_line *command, char **temp, t_data *d)
{
	int	yndex;
	int	i;

	yndex = -1;
	while (temp[++yndex])
	{
		command->cmd[yndex] = parsing(temp[yndex], d);
		if (!command->cmd[yndex])
		{
			i = 0;
			while (i < yndex)
				free(command->cmd[i++]);
			return (-1);
		}
		if (handle_special_var(command, yndex) == -1)
		{
			i = 0;
			while (i < yndex)
				free(command->cmd[i++]);
			return (-1);
		}
	}
	command->cmd[yndex] = NULL;
	return (yndex);
}

int	prepare_cmd_array(t_shell_line *command, t_temp_redir *redir,
	char ***temp)
{
	int	len;

	*temp = parsing_split(redir->without_redir, ' ');
	if (!*temp)
	{
		if (redir->without_redir && redir->without_redir != redir->line)
			free(redir->without_redir);
		free(redir);
		free(command->line);
		free(command);
		return (0);
	}
	len = parsing_count_words(redir->without_redir, ' ') + 1;
	command->cmd = (char **)ft_calloc(sizeof(char *), len);
	if (!command->cmd)
	{
		cleanup_resources(redir, command, *temp, 0);
		return (0);
	}
	return (1);
}

t_shell_line	*init_command(t_temp_redir *redir)
{
	t_shell_line	*command;

	if (!redir)
		return (NULL);
	command = (t_shell_line *)ft_calloc(1, sizeof(t_shell_line));
	if (!command)
	{
		if (redir->without_redir && redir->without_redir != redir->line)
			free(redir->without_redir);
		free(redir);
		return (NULL);
	}
	command->redir = redir->redir;
	command->empty_quoted_var = 0;
	command->line = ft_strtrim(redir->without_redir, " \t");
	if (!command->line)
	{
		if (redir->without_redir && redir->without_redir != redir->line)
			free(redir->without_redir);
		free(redir);
		free(command);
		return (NULL);
	}
	return (command);
}

t_shell_line	*command_node(t_temp_redir *redir, t_data *d)
{
	t_shell_line	*command;
	char			**temp;

	command = init_command(redir);
	if (!command)
		return (NULL);
	if (!prepare_cmd_array(command, redir, &temp))
		return (NULL);
	if (process_cmd_args(command, temp, d) == -1)
	{
		cleanup_resources(redir, command, temp, 1);
		return (NULL);
	}
	array_free(temp);
	command->next = NULL;
	if (redir->without_redir && redir->without_redir != redir->line)
		free(redir->without_redir);
	free(redir);
	return (command);
}
