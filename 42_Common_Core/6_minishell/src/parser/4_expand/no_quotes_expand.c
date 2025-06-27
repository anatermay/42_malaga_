/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quotes_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 00:26:05 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*no_quotes_expand_2(t_data *d, char *expanded, char *str,
	int *index)
{
	if (str[*index] == '$' && str[*index + 1]
		&& is_space(str[*index + 1]) == 0)
	{
		(*index)++;
		expanded = process_env_variable(d, expanded, str, index);
		if (!expanded)
			return (NULL);
	}
	else
	{
		expanded = continue_expand(expanded, str[*index]);
		if (!expanded)
			return (NULL);
		(*index)++;
	}
	return (expanded);
}

char	*no_quotes_expand(char *str, t_data *d)
{
	char	*expanded;
	int		index;

	if (!str)
		return (NULL);
	if (is_there_dollars(str) == 0)
		return (ft_strdup(str));
	expanded = ft_strdup("");
	if (!expanded)
		return (NULL);
	index = 0;
	while (str[index])
	{
		expanded = no_quotes_expand_2(d, expanded, str, &index);
		if (!expanded)
		{
			free(expanded);
			return (NULL);
		}
	}
	return (expanded);
}
