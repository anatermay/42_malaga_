/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 23:42:40 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	flag_calculator(char *line, int index, int quote)
{
	if (!line || index < 0 || (size_t)index >= ft_strlen(line))
		return (quote);
	if (line[index] == '\"' && quote == 0)
		return (1);
	else if (line[index] == '\"' && quote == 1)
		return (0);
	else if (line[index] == '\'' && quote == 0)
		return (2);
	else if (line[index] == '\'' && quote == 2)
		return (0);
	return (quote);
}

char	*ft_strndup(const char *str, int init)
{
	char	*dup;
	int		end;
	int		index;

	end = ft_strlen((char *)str) - 1;
	while (str[end])
	{
		if (is_space(str[end]) == 0)
			break ;
		end--;
	}
	dup = malloc((end - init) + 2);
	if (!dup)
		return (NULL);
	index = 0;
	while (init <= end && str[init])
	{
		dup[index] = str[init];
		index++;
		init++;
	}
	dup[index] = '\0';
	return (dup);
}
