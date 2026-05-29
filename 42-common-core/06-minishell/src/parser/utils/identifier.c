/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 23:10:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_c(char c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	no_space_finder(char *str)
{
	int	index;

	index = 0;
	while (str[index] && is_space(str[index]) == 1)
		index++;
	return (index);
}

int	is_there_dollars(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == 36)
			return (1);
		index++;
	}
	return (0);
}

int	is_there_quotes(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == 34)
			return (2);
		else if (str[index] == 39)
			return (1);
		index++;
	}
	return (0);
}
