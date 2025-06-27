/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_2_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:00:00 by aternero          #+#    #+#             */
/*   Updated: 2025/01/02 00:00:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	process_redirect_token(char **ret, char *str, int *index, int start)
{
	if (index[0] > start)
		ret[index[1]] = ft_substr(str, start, index[0] - start);
	else
		ret[index[1]] = ft_strdup("");
	if (!ret[index[1]])
		return (0);
	index[1]++;
	return (1);
}

int	process_file_token(char **ret, char *str, int *index)
{
	int	start;

	start = index[0];
	redir_splited_4(str, index);
	if (index[0] > start)
		ret[index[1]] = ft_substr(str, start, index[0] - start);
	else
		ret[index[1]] = ft_strdup("");
	if (!ret[index[1]])
		return (0);
	index[1]++;
	return (1);
}

int	handle_redirect_in_quote(char *str, int *index)
{
	index[2] = flag_calculator((char *)str, index[0], index[2]);
	index[0]++;
	if (str[index[0]] && is_space(str[index[0]]))
		index[2] = flag_calculator((char *)str, index[0], index[2]);
	return (1);
}

int	handle_other_char(char *str, int *index)
{
	index[2] = flag_calculator((char *)str, index[0], index[2]);
	index[0]++;
	return (1);
}
