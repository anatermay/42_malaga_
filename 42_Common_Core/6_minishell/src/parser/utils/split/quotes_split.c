/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 19:10:44 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	words_counter_2(const char *str, int *index)
{
	char	c;

	c = str[index[0]];
	index[2]++;
	index[0]++;
	while (str[index[0]] && str[index[0]] != c)
		index[0]++;
	if (str[index[0]])
		index[0]++;
	index[1] = 0;
}

static int	words_counter(const char *str)
{
	int		index[3];

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (str[index[0]])
	{
		if (!is_c(str[index[0]]))
		{
			if (!index[1])
			{
				index[2]++;
				index[1] = 1;
			}
			index[0]++;
		}
		else
			words_counter_2(str, index);
	}
	return (index[2]);
}

static int	quoted_splited_2(const char *str, int *index,
	int *yndex, char **ret)
{
	char	c;
	int		start;

	start = (*index);
	c = str[(*index)];
	(*index)++;
	while (str[(*index)] && str[(*index)] != c)
		(*index)++;
	if (str[(*index)])
		(*index)++;
	ret[(*yndex)] = ft_substr(str, start, (*index) - start);
	if (!ret[(*yndex)])
		return (0);
	(*yndex)++;
	return (1);
}

static char	**quoted_splited(const char *str, char **ret)
{
	int		index;
	int		start;
	int		yndex;

	index = 0;
	yndex = 0;
	while (str[index])
	{
		if (str[index] && !is_c(str[index]))
		{
			start = index;
			while (str[index] && !is_c(str[index]))
				index++;
			ret[yndex] = ft_substr(str, start, index - start);
			if (!ret[yndex])
				return (array_free(ret));
			yndex++;
		}
		if (str[index] && is_c(str[index]))
		{
			if (!quoted_splited_2(str, &index, &yndex, ret))
				return (array_free(ret));
		}
	}
	return (ret[yndex] = NULL, ret);
}

char	**quote_parsing_split(const char *str)
{
	char	**ret;
	int		words;

	words = words_counter(str);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	if (!quoted_splited(str, ret))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
