/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 16:33:54 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*parsing(char *str, t_data *d)
{
	char	*cmd;
	char	*tilde_expanded;

	tilde_expanded = expand_tilde(str, d);
	if (!tilde_expanded)
		return (NULL);
	if (is_there_quotes(tilde_expanded) == 0)
	{
		cmd = no_quotes_expand(tilde_expanded, d);
		free(tilde_expanded);
		if (!cmd)
			return (NULL);
		return (cmd);
	}
	else
	{
		cmd = parsing_continue(tilde_expanded, d);
		free(tilde_expanded);
		if (!cmd)
			return (NULL);
		return (cmd);
	}
}
