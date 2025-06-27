/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:00:00 by aternero          #+#    #+#             */
/*   Updated: 2025/01/02 00:00:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_temp	*add_first_node(char **array, int index)
{
	t_temp	*temp;

	temp = temp_node_1(array[index]);
	if (!temp)
	{
		array_free(array);
		return (NULL);
	}
	return (temp);
}

t_temp	*add_next_node(t_temp *temp, char **array, int index)
{
	t_temp	*temp_b;

	temp_b = temp;
	while (temp_b->next)
		temp_b = temp_b->next;
	temp_b->next = temp_node_1(array[index]);
	if (!temp_b->next)
	{
		array_free(array);
		return (NULL);
	}
	return (temp);
}
