/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:17:42 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 22:27:36 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	words_counter_2(char *str, int *index, int *words, int quote)
{
	char	quote_char;

	(*words)++;
	while (str[*index] && is_space(str[*index]) == 0)
	{
		if (str[*index] == '"' || str[*index] == '\'')
		{
			quote_char = str[*index];
			quote = flag_calculator((char *)str, *index, quote);
			(*index)++;
			while (str[*index] && str[*index] != quote_char)
				(*index)++;
			if (str[*index] == quote_char)
			{
				quote = flag_calculator((char *)str, *index, quote);
				(*index)++;
			}
		}
		else
		{
			quote = flag_calculator((char *)str, *index, quote);
			(*index)++;
		}
	}
}

static void	words_counter_1(char *str, int *index, int *words, int quote)
{
	if (is_redirect(str[*index]) && quote == 0)
	{
		(*words)++;
		while (str[*index] && is_redirect(str[*index])
			&& flag_calculator((char *)str, *index, quote) == 0)
		{
			quote = flag_calculator((char *)str, *index, quote);
			(*index)++;
		}
		while (str[*index] && is_space(str[*index]))
			(*index)++;
		if (str[*index])
		{
			words_counter_2((char *)str, index, words, quote);
			(*index)--;
		}
	}
	else
		quote = flag_calculator((char *)str, *index, quote);
	(*index)++;
}

int	redir_words_counter(const char *str)
{
	int		index;
	int		words;
	int		quote;

	index = 0;
	quote = 0;
	if (!is_redirect(str[0]))
		words = 1;
	else
		words = 0;
	while (str[index])
	{
		quote = flag_calculator((char *)str, index, quote);
		words_counter_1((char *)str, &index, &words, quote);
	}
	return (words);
}
