/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_redirect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 00:45:56 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_redirect	*init_redirect_1(t_redirect *redir, char **lines, int yndex)
{
	t_redirect	*temp;

	temp = NULL;
	if (!redir)
		return (new_redir_node(lines, lines[yndex], yndex));
	temp = redir;
	while (temp->next)
		temp = temp->next;
	temp->next = new_redir_node(lines, lines[yndex], yndex);
	return (redir);
}

t_redirect	*init_redirect(char **lines)
{
	t_redirect	*redir;
	int			yndex;

	if (!lines)
		return (NULL);
	yndex = 0;
	redir = NULL;
	while (lines[yndex])
	{
		if (lines[yndex][0] && is_redirect(lines[yndex][0]))
		{
			redir = init_redirect_1(redir, lines, yndex);
			if (!redir)
				break ;
		}
		yndex++;
	}
	array_free(lines);
	if (!redir)
		return (NULL);
	return (redir);
}
