/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 21:37:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	there_is_redir(char *str)
{
	int	index;
	int	in_quote;
	int	count;

	index = 0;
	in_quote = 0;
	count = 0;
	while (str[index])
	{
		in_quote = flag_calculator(str, index, in_quote);
		if (is_redirect(str[index]) == 1 && !in_quote)
			count++;
		index++;
	}
	return (count);
}

int	is_redirect(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

static void	redir_length_1(char *str, int *index, int *length)
{
	while (str[*index] && is_redirect(str[*index]) == 1)
	{
		(*index)++;
		(*length)++;
	}
	while (str[*index] && is_space(str[*index]) == 1)
	{
		(*index)++;
		(*length)++;
	}
	while (str[*index] && is_space(str[*index]) == 0
		&& is_redirect(str[*index]) == 0)
	{
		(*index)++;
		(*length)++;
	}
}

int	redir_length(char *str)
{
	int	index;
	int	length;
	int	quote;

	index = 0;
	length = 0;
	quote = 0;
	while (str[index])
	{
		quote = flag_calculator(str, index, quote);
		if (is_redirect(str[index]) == 1 && quote == 0)
			redir_length_1(str, &index, &length);
		else
			index++;
	}
	return (length);
}
