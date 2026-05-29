/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 01:03:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	**redir_split(const char *str)
{
	char	**ret;
	int		words;
	int		final_count;
	int		i;

	words = redir_words_counter(str);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i <= words)
	{
		ret[i] = NULL;
		i++;
	}
	final_count = 0;
	if (!redir_splited(str, ret, &final_count))
	{
		array_free(ret);
		return (NULL);
	}
	return (ret);
}
