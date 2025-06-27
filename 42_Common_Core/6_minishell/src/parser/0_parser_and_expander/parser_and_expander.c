/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_expander.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_initial_tokens(t_data *d)
{
	int	index;

	if (!d || !d->line)
		return (1);
	index = 0;
	while (d->line[index] && (d->line[index] == ' '
			|| d->line[index] == '\t'))
		index++;
	if (d->line[index] == '#')
	{
		d->exit_status = 0;
		return (1);
	}
	if (d->line[index] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		d->exit_status = 2;
		return (1);
	}
	return (0);
}

static int	check_ampersand_and_parentheses(t_data *d)
{
	int	index;
	int	quote;
	int	first_non_space;
	int	result;

	if (!d || !d->line)
		return (1);
	index = 0;
	quote = 0;
	first_non_space = 1;
	while (d->line[index])
	{
		result = process_char_in_loop(d, index, quote, first_non_space);
		if (result == -1)
			return (1);
		if (result == -2)
			break ;
		quote = result;
		if (d->line[index] != ' ' && d->line[index] != '\t')
			first_non_space = 0;
		index++;
	}
	return (0);
}

int	pre_process(t_data *d)
{
	if (check_initial_tokens(d) == 1)
		return (1);
	if (check_ampersand_and_parentheses(d) == 1)
		return (1);
	if (check_pipes_and_redirects(d) == 1)
		return (1);
	return (0);
}
