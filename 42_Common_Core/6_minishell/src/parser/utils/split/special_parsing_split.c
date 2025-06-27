/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_parsing_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 20:21:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	parsing_count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	inside_word;
	int	quote;

	i = 0;
	words = 0;
	inside_word = 0;
	quote = 0;
	while (s[i])
	{
		quote = flag_calculator((char *)s, i, quote);
		if ((s[i] != c || quote != 0) && !inside_word)
		{
			words++;
			inside_word = 1;
		}
		else if (s[i] == c && quote == 0)
			inside_word = 0;
		i++;
	}
	return (words);
}

static size_t	parsing_count_word_size(char const *s, char c, size_t start)
{
	size_t	letters;
	int		quote;

	letters = 0;
	quote = 0;
	while (s[start + letters])
	{
		quote = flag_calculator((char *)s, start + letters, quote);
		if (s[start + letters] == c && quote == 0)
			break ;
		letters++;
	}
	return (letters);
}

static char	**parsing_splited_split(const char *s, char **array, char c)
{
	int	tn[4];

	tn[0] = -1;
	tn[1] = 0;
	tn[2] = 0;
	tn[3] = 0;
	while (s[++tn[0]])
	{
		tn[3] = flag_calculator((char *)s, tn[0], tn[3]);
		if ((s[tn[0]] != c || tn[3] != 0) && !tn[2])
		{
			tn[2] = 1;
			array[tn[1]] = ft_substr(s, tn[0],
					parsing_count_word_size(s, c, tn[0]));
			if (!array[tn[1]])
			{
				array_free(array);
				return (NULL);
			}
			tn[1]++;
		}
		else if (s[tn[0]] == c && tn[3] == 0)
			tn[2] = 0;
	}
	return (array);
}

static char	*parsing_split_2(char **array, int index)
{
	char	*trimmed;
	char	*temp;
	int		x;

	temp = array[index];
	trimmed = ft_strtrim(temp, " \t");
	if (trimmed)
	{
		array[index] = ft_strdup(trimmed);
		free(trimmed);
	}
	else
		array[index] = ft_strdup("");
	free(temp);
	if (!array[index])
	{
		x = 0;
		while (x < index)
			free(array[x++]);
		free(array);
		return (NULL);
	}
	return (array[index]);
}

char	**parsing_split(char const *s, char c)
{
	char	**array;
	int		word_count;
	int		index;

	word_count = parsing_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!parsing_splited_split(s, array, c))
		return (NULL);
	array[word_count] = NULL;
	index = 0;
	while (array[index])
	{
		array[index] = parsing_split_2(array, index);
		index++;
	}
	return (array);
}
