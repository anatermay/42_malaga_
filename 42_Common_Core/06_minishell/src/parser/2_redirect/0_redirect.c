/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_redirect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:37:07 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 00:26:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	skip_redir_and_type(char *str, int *sindex)
{
	char	quote_char;

	while (str[*sindex] && is_redirect(str[*sindex]) == 1
		&& is_space(str[*sindex]) == 0)
		(*sindex)++;
	while (str[*sindex] && is_space(str[*sindex]) == 1)
		sindex++;
	while (str[*sindex] && is_space(str[*sindex]) == 0)
	{
		if (str[*sindex] == '"' || str[*sindex] == '\'')
		{
			quote_char = str[*sindex];
			(*sindex)++;
			while (str[*sindex] && str[*sindex] != quote_char)
				(*sindex)++;
			if (str[*sindex] == quote_char)
				(*sindex)++;
		}
		else
			(*sindex)++;
	}
	while (str[*sindex] && is_space(str[*sindex]) == 1)
		(*sindex)++;
}

static int	line_length(char *str)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (str[index])
	{
		if (is_redirect(str[index]) == 1)
		{
			while (str[index] && is_redirect(str[index]) == 1)
				index++;
			while (str[index] && is_space(str[index]) == 1)
				index++;
			while (str[index] && is_space(str[index]) == 0)
				index++;
		}
		else
		{
			len++;
			index++;
		}
	}
	return (len);
}

char	*init_without_redir(char *str)
{
	char	*line;
	int		index[2];
	int		quote;
	int		len;

	len = line_length(str);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	quote = 0;
	while (str[index[0]] && index[0] < len)
	{
		quote = flag_calculator(str, index[0], quote);
		if (is_redirect(str[index[0]]) == 1 && quote == 0)
			skip_redir_and_type(str, &index[0]);
		else
		{
			line[index[1]++] = str[index[0]];
			index[0]++;
		}
	}
	line[index[1]] = '\0';
	return (line);
}

static t_temp_redir	*redirect_1(t_temp_redir *redir, char *str, int len)
{
	char	*without_ampersand;

	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'))
		len--;
	if (len > 0 && str[len - 1] == '&')
	{
		without_ampersand = init_without_redir(str);
		if (!without_ampersand)
		{
			free(redir);
			return (NULL);
		}
		redir->line = str;
		redir->without_redir = without_ampersand;
		redir->redir = NULL;
		return (redir);
	}
	else
	{
		redir->line = str;
		redir->without_redir = str;
		redir->redir = NULL;
		return (redir);
	}
}

t_temp_redir	*redirect(char *str)
{
	t_temp_redir	*redir;
	char			*line;

	redir = (t_temp_redir *)malloc(sizeof(t_temp_redir));
	if (!redir)
		return (NULL);
	if (!there_is_redir(str))
		return (redirect_1(redir, str, ft_strlen(str)));
	line = init_without_redir(str);
	if (!line)
	{
		free(redir);
		return (NULL);
	}
	redir->without_redir = line;
	redir->redir = init_redirect(redir_split(str));
	if (!redir->redir)
	{
		free(redir->without_redir);
		free(redir);
		return (NULL);
	}
	return (redir);
}
