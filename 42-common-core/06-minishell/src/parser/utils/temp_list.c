/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 22:46:10 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_list(t_temp *temp)
{
	t_temp	*current;
	t_temp	*next;

	current = temp;
	while (current)
	{
		next = current->next;
		if (current->sub)
			free(current->sub);
		if (current->expanded)
			free(current->expanded);
		free(current);
		current = next;
	}
}

static t_temp	*temp_node_2(t_temp *new, char *str)
{
	if (str[0] == 34)
	{
		new->quote = 2;
		if (ft_strlen(str) == 2 && str[1] == 34)
			new->sub = ft_strdup("");
		else
			new->sub = ft_strtrim(str, "\"");
	}
	else if (str[0] == 39)
	{
		new->quote = 1;
		if (ft_strlen(str) == 2 && str[1] == 39)
			new->sub = ft_strdup("");
		else
			new->sub = ft_strtrim(str, "\'");
	}
	else
	{
		new->quote = 0;
		new->sub = ft_strdup(str);
	}
	return (new);
}

t_temp	*temp_node_1(char *str)
{
	t_temp	*new;

	new = (t_temp *)ft_calloc(1, sizeof(t_temp));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	new = temp_node_2(new, str);
	if (!new->sub)
	{
		free(new);
		return (NULL);
	}
	new->expanded = NULL;
	new->next = NULL;
	return (new);
}

static t_temp	*temp_node_0(t_temp *temp, char **array, int index)
{
	if (!temp)
		return (add_first_node(array, index));
	else
		return (add_next_node(temp, array, index));
}

t_temp	*temp_list(char **array)
{
	t_temp	*temp;
	int		index;

	index = -1;
	temp = NULL;
	while (array[++index])
	{
		temp = temp_node_0(temp, array, index);
		if (!temp)
			return (NULL);
	}
	return (temp);
}
