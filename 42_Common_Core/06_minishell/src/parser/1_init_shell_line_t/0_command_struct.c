/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_command_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:19:52 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 23:39:16 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	command_struct_2(t_shell_line **cmd, t_shell_line *new)
{
	t_shell_line	*temp;

	temp = NULL;
	if (!(*cmd))
	{
		*cmd = new;
		new->next = NULL;
	}
	else
	{
		temp = *cmd;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
}

t_shell_line	*command_struct(char *line, t_data *d)
{
	t_shell_line	*commands;
	t_shell_line	*new_command;
	char			**lines;
	int				index;

	index = 0;
	lines = parsing_split(line, '|');
	commands = NULL;
	while (lines[index])
	{
		new_command = command_node(redirect(lines[index]), d);
		if (!new_command)
		{
			if (commands)
				free_shell_line(commands);
			if (lines)
				array_free(lines);
			return (NULL);
		}
		command_struct_2(&commands, new_command);
		index++;
	}
	if (lines)
		array_free(lines);
	return (commands);
}
