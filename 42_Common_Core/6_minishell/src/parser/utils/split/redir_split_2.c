/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:02:52 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 00:54:43 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	redir_splited_4(char *str, int *index)
{
	char	quote_char;

	while (str[index[0]] && is_space(str[index[0]]) == 0)
	{
		if (str[index[0]] == '"' || str[index[0]] == '\'')
		{
			quote_char = str[index[0]];
			index[2] = flag_calculator((char *)str, index[0], index[2]);
			index[0]++;
			while (str[index[0]] && str[index[0]] != quote_char)
				index[0]++;
			if (str[index[0]] == quote_char)
			{
				index[2] = flag_calculator((char *)str, index[0], index[2]);
				index[0]++;
			}
		}
		else
		{
			index[2] = flag_calculator((char *)str, index[0], index[2]);
			index[0]++;
		}
	}
}

static int	redir_splited_3(char **ret, char *str, int *index)
{
	int	start;

	start = index[0];
	while (str[index[0]] && is_redirect(str[index[0]])
		&& flag_calculator((char *)str, index[0], index[2]) == 0)
	{
		index[2] = flag_calculator((char *)str, index[0], index[2]);
		index[0]++;
	}
	if (!process_redirect_token(ret, str, index, start))
		return (0);
	while (str[index[0]] && is_space(str[index[0]]))
		index[0]++;
	if (str[index[0]])
	{
		if (!process_file_token(ret, str, index))
			return (0);
	}
	return (1);
}

static int	redir_splited_2(char **ret, char *str, int *index)
{
	int	start;

	start = index[0];
	while (str[index[0]] && (!is_redirect(str[index[0]])
			|| flag_calculator((char *)str, index[0], index[2]) != 0))
	{
		index[2] = flag_calculator((char *)str, index[0], index[2]);
		index[0]++;
	}
	if (index[0] > start)
		ret[index[1]] = ft_substr(str, start, index[0] - start);
	else
		ret[index[1]] = ft_strdup("");
	if (!ret[index[1]])
		return (0);
	index[1]++;
	return (1);
}

static int	redir_splited_1(char **ret, char *str, int *index)
{
	if (str[index[0]] && (!is_redirect(str[index[0]]) || index[2] != 0))
		return (redir_splited_2(ret, str, index));
	else if (str[index[0]] && is_redirect(str[index[0]]) && index[2] == 0)
		return (redir_splited_3(ret, str, index));
	else if (str[index[0]] && is_redirect(str[index[0]]) && index[2] != 0)
		return (handle_redirect_in_quote(str, index));
	else
		return (handle_other_char(str, index));
}

char	**redir_splited(const char *str, char **ret, int *final_count)
{
	int		index[3];

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (str[index[0]])
	{
		while (str[index[0]] && is_space(str[index[0]]))
			index[0]++;
		if (!str[index[0]])
			break ;
		index[2] = flag_calculator((char *)str, index[0], index[2]);
		if (!redir_splited_1(ret, (char *)str, index))
		{
			array_free(ret);
			return (NULL);
		}
	}
	ret[index[1]] = NULL;
	*final_count = index[1];
	return (ret);
}
