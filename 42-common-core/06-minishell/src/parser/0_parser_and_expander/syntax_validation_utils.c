/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_validation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:00:00 by aternero          #+#    #+#             */
/*   Updated: 2025/01/02 00:00:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	process_special_char(t_data *d, int *index)
{
	if (d->line[*index] == '\'' || d->line[*index] == '"')
	{
		if (!skip_quotes(d->line, index))
			return (0);
	}
	else if (d->line[*index] == '|')
	{
		if (check_pipe_syntax(d, *index) == 1)
			return (1);
		(*index)++;
	}
	else if (d->line[*index] == '>' || d->line[*index] == '<')
	{
		if (check_redirect_syntax(d, index) == 1)
			return (1);
	}
	else
		(*index)++;
	return (0);
}

int	check_redirect_syntax(t_data *d, int *index)
{
	(*index)++;
	if (d->line[*index] == d->line[*index - 1])
		(*index)++;
	while (d->line[*index] && (d->line[*index] == ' '
			|| d->line[*index] == '\t'))
		(*index)++;
	if (!d->line[*index] || d->line[*index] == '|'
		|| d->line[*index] == '>' || d->line[*index] == '<')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (!d->line[*index])
			ft_putstr_fd("newline", 2);
		else
			ft_putchar_fd(d->line[*index], 2);
		ft_putstr_fd("'\n", 2);
		d->exit_status = 2;
		return (1);
	}
	return (0);
}

int	check_pipes_and_redirects(t_data *d)
{
	int	index;
	int	result;

	if (!d || !d->line)
		return (1);
	index = 0;
	while (d->line[index])
	{
		result = process_special_char(d, &index);
		if (result == 1)
			return (1);
	}
	return (0);
}
