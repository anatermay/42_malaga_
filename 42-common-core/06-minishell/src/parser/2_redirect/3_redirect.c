/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_redirect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:16:06 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 22:57:18 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*remove_redir_quotation_2(char **splited, char *ret, int index)
{
	char	*temp;
	int		len;

	if (splited[index][0] == '"' || splited[index][0] == '\'')
	{
		len = ft_strlen(splited[index]);
		if (len >= 2 && splited[index][0] == splited[index][len - 1])
			temp = ft_substr(splited[index], 1, len - 2);
		else
			temp = ft_strdup(splited[index]);
	}
	else
		temp = ft_strdup(splited[index]);
	if (!temp)
	{
		if (ret)
			free(ret);
		array_free(splited);
		return (NULL);
	}
	return (temp);
}

char	*remove_redir_quotation_1(char **splited, char *ret, int index)
{
	char	*temp;
	char	*new_ret;

	temp = remove_redir_quotation_2(splited, ret, index);
	if (!temp)
		return (NULL);
	if (!ret)
		ret = temp;
	else
	{
		new_ret = ft_strjoin(ret, temp);
		free(ret);
		free(temp);
		ret = new_ret;
		if (!ret)
		{
			array_free(splited);
			return (NULL);
		}
	}
	return (ret);
}

char	*remove_redir_quotation(char *file)
{
	char	**splited;
	char	*ret;
	int		index;

	if (!file)
		return (NULL);
	splited = quote_parsing_split(file);
	index = -1;
	ret = NULL;
	while (splited[++index])
	{
		ret = remove_redir_quotation_1(splited, ret, index);
		if (!ret)
		{
			array_free(splited);
			return (NULL);
		}
	}
	array_free(splited);
	return (ret);
}
