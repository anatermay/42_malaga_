/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_quotes(char *line, int *index)
{
	char	quote;

	quote = line[*index];
	(*index)++;
	while (line[*index] && line[*index] != quote)
		(*index)++;
	if (line[*index] == quote)
	{
		(*index)++;
		return (1);
	}
	return (0);
}

void	print_ampersand_error(t_data *d, int index)
{
	if (d->line[index + 1] == '&')
	{
		if (d->line[index + 2] == '&')
			ft_putstr_fd("minishell: syntax error near unexpected "
				"token `&'\n", 2);
		else
			ft_putstr_fd("minishell: syntax error near unexpected "
				"token `&&'\n", 2);
	}
	else
		ft_putstr_fd("minishell: syntax error near unexpected "
			"token `&'\n", 2);
	d->exit_status = 2;
}

int	handle_ampersand_error(t_data *d, int index, int first_non_space)
{
	int	j;

	if (d->line[index + 1] == '&')
	{
		print_ampersand_error(d, index);
		return (1);
	}
	if (first_non_space)
	{
		print_ampersand_error(d, index);
		return (1);
	}
	j = index + 1;
	while (d->line[j] && (d->line[j] == ' ' || d->line[j] == '\t'))
		j++;
	if (d->line[j] != '\0')
	{
		print_ampersand_error(d, index);
		return (1);
	}
	return (0);
}

int	process_char_in_loop(t_data *d, int index, int quote, int first_non_space)
{
	if (d->line[index] == '"' || d->line[index] == '\'')
		return (flag_calculator(d->line, index, quote));
	if (quote == 0)
	{
		if (d->line[index] == '&')
		{
			if (handle_ampersand_error(d, index, first_non_space) == 1)
				return (-1);
			if (d->line[index + 1] != '&')
				return (-2);
		}
		else if (d->line[index] == '(' || d->line[index] == ')')
		{
			ft_putstr_fd("minishell: syntax error near unexpected "
				"token `)'\n", 2);
			d->exit_status = 2;
			return (-1);
		}
	}
	return (quote);
}

int	check_pipe_syntax(t_data *d, int index)
{
	int	next;

	next = index + 1;
	while (d->line[next] && (d->line[next] == ' ' || d->line[next] == '\t'))
		next++;
	if (!d->line[next] || d->line[next] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (!d->line[next])
			ft_putstr_fd("newline", 2);
		else
			ft_putstr_fd("|", 2);
		ft_putstr_fd("'\n", 2);
		d->exit_status = 2;
		return (1);
	}
	return (0);
}
