/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 22:48:19 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*to_expand_and_join_2(t_temp *temp)
{
	t_temp	*temp_b;
	char	*join;
	char	*tem;

	temp_b = temp;
	join = NULL;
	while (temp_b)
	{
		if (!join)
			join = ft_strdup(temp_b->expanded);
		else
		{
			tem = join;
			join = ft_strjoin(join, temp_b->expanded);
			free(tem);
			if (!join)
				return (NULL);
		}
		temp_b = temp_b->next;
	}
	return (join);
}

static void	to_expand_and_join_1(t_temp *temp, t_data *d)
{
	t_temp	*temp_b;

	temp_b = temp;
	while (temp_b)
	{
		if (temp_b->quote == 0 || temp_b->quote == 2)
		{
			temp_b->expanded = no_quotes_expand(temp_b->sub, d);
			if (temp_b->quote == 2 && temp_b->expanded
				&& temp_b->expanded[0] == '\0'
				&& temp_b->sub && ft_strchr(temp_b->sub, '$'))
			{
				free(temp_b->expanded);
				temp_b->expanded = ft_strdup("\x01");
			}
		}
		else
			temp_b->expanded = ft_strdup(temp_b->sub);
		if (!temp_b->expanded)
			temp_b->expanded = ft_strdup("");
		temp_b = temp_b->next;
	}
}

char	*to_expand_and_join(t_temp *temp, t_data *d)
{
	to_expand_and_join_1(temp, d);
	return (to_expand_and_join_2(temp));
}
