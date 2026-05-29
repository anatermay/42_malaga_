/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 21:32:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*parsing_continue_2(char *str, t_data *d)
{
	t_temp	*temp;
	char	**split;
	char	*ret;

	split = quote_parsing_split(str);
	if (!split)
		return (NULL);
	temp = temp_list(split);
	if (!temp)
	{
		array_free(split);
		return (NULL);
	}
	ret = to_expand_and_join(temp, d);
	array_free(split);
	free_list(temp);
	return (ret);
}

static void	quotes_counter(char *str, int *dob, int *sin)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (str[index] == 34)
			(*dob)++;
		if (str[index] == 39)
			(*sin)++;
	}
}

char	*parsing_continue(char *str, t_data *d)
{
	int		quotes[2];
	char	*no_quotes_str;
	char	*expanded_str;
	char	*result;

	quotes[0] = 0;
	quotes[1] = 0;
	quotes_counter(str, &quotes[0], &quotes[1]);
	if (quotes[1] > 0 && quotes[0] > 0)
		return (parsing_continue_2(str, d));
	else if (is_there_dollars(str) == 0 || (quotes[0] > 0 && quotes[1] == 0))
	{
		no_quotes_str = remove_quotes(str);
		if (!no_quotes_str)
			return (NULL);
		expanded_str = no_quotes_expand(no_quotes_str, d);
		free(no_quotes_str);
		if (!expanded_str)
			return (NULL);
		result = expanded_str;
		return (result);
	}
	else if (quotes[1] > 0 && quotes[0] == 0)
		return (remove_quotes(str));
	return (str);
}
