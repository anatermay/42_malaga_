/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:27:56 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 23:44:15 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	quote_chars_counter(char *str)
{
	int	index[2];
	int	in_quote;

	index[0] = -1;
	index[1] = 0;
	in_quote = 0;
	while (str[++index[0]])
	{
		if (str[index[0]] == 34 || str[index[0]] == 39)
			index[1]++;
		in_quote = flag_calculator(str, index[0], in_quote);
	}
	return (index[1]);
}

static void	remove_quotes_1(char *str, char *ret, int *index, int in_quote)
{
	char	quote;

	if ((in_quote == 1 && str[index[0]] == 34)
		|| (in_quote == 2 && str[index[0]] == 39))
	{
		quote = str[index[0]];
		if (str[index[0] + 1] && str[index[0] + 1] == quote)
			index[0] += 2;
		else
			index[0]++;
	}
	ret[index[1]] = str[index[0]];
	index[1]++;
}

char	*remove_quotes(char *str)
{
	char	*ret;
	int		index[2];
	int		in_quote;

	index[0] = ft_strlen(str);
	index[1] = quote_chars_counter(str);
	ret = malloc(sizeof(char) * (index[0] - index[1] + 1));
	if (!ret)
		return (NULL);
	index[0] = -1;
	index[1] = 0;
	in_quote = 0;
	while (str[++index[0]])
	{
		in_quote = flag_calculator(str, index[0], in_quote);
		if ((str[index[0]] != 34 && str[index[0]] != 39)
			|| (in_quote && (str[index[0]] == 39 || str[index[0]] == 34)))
			remove_quotes_1(str, ret, index, in_quote);
	}
	ret[index[1]] = '\0';
	return (ret);
}
