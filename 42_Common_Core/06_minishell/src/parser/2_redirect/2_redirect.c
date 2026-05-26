/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_redirect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:02:43 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 01:02:23 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redirect	*new_redir_node_3(t_redirect *redir, char **lines,
	int *yndex, int start)
{
	char		*temp_file;

	temp_file = ft_substr(lines[*yndex], start,
			ft_strlen(lines[*yndex]) - start);
	if (!temp_file)
	{
		free(redir->type);
		free(redir);
		return (NULL);
	}
	redir->file = remove_redir_quotation(temp_file);
	free(temp_file);
	if (!redir->file)
	{
		free(redir->type);
		free(redir);
		return (NULL);
	}
	return (redir);
}

t_redirect	*new_redir_node_2(t_redirect *redir, char **lines,
	int *yndex, int start)
{
	if (lines[*yndex][start] == 34 || lines[*yndex][start] == 39)
	{
		redir = new_redir_node_3(redir, lines, yndex, start);
		if (!redir)
			return (NULL);
	}
	else
	{
		redir->file = ft_substr(lines[*yndex], start,
				ft_strlen(lines[*yndex]) - start);
		if (!redir->file)
		{
			free(redir->type);
			free(redir);
			return (NULL);
		}
	}
	return (redir);
}

static int	if_increment(int *yndex, t_redirect *redir, char **lines)
{
	if (lines[*yndex + 1])
		(*yndex)++;
	else
	{
		free(redir->type);
		free(redir);
		return (0);
	}
	return (1);
}

static t_redirect	*new_redir_node_1(t_redirect *redir, char **lines,
	int *yndex)
{
	char		quote_char;
	int			index;
	int			start;

	if (!if_increment(yndex, redir, lines))
		return (NULL);
	index = 0;
	while (lines[*yndex][index] && is_space(lines[*yndex][index]) == 1)
		index++;
	start = index;
	while (lines[*yndex][index] && is_space(lines[*yndex][index]) == 0)
	{
		if (lines[*yndex][index] == '\"' || lines[*yndex][index] == '\'')
		{
			quote_char = lines[*yndex][index];
			index++;
			while (lines[*yndex][index] && lines[*yndex][index] != quote_char)
				index++;
			if (lines[*yndex][index] == quote_char)
				index++;
		}
		else
			index++;
	}
	return (new_redir_node_2(redir, lines, yndex, start));
}

t_redirect	*new_redir_node(char **lines, char *line, int yndex)
{
	t_redirect	*redir;

	redir = (t_redirect *)malloc(sizeof(t_redirect));
	if (!redir)
		return (NULL);
	redir->type = ft_strdup(line);
	if (!redir->type)
	{
		free(redir);
		return (NULL);
	}
	if (lines[yndex + 1])
	{
		redir = new_redir_node_1(redir, lines, &yndex);
		if (!redir)
			return (NULL);
	}
	else
		redir->file = NULL;
	redir->next = NULL;
	return (redir);
}
