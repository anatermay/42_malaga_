/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 18:58:06 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal_sigint(t_data *d)
{
	d->exit_status = 130;
	g_signal = S_BASE;
	if (d->line && d->line[0] != '\0')
	{
		add_history(d->line);
		free(d->line);
		d->line = NULL;
	}
}

void	handle_signal_sigint_cmd(t_data *d)
{
	d->exit_status = 130;
	g_signal = S_BASE;
}

int	process_input(t_data *d)
{
	int	error;

	if (d->line && d->line[0] != '\0')
		add_history(d->line);
	error = pre_process(d);
	if (error)
	{
		free(d->line);
		d->line = NULL;
		return (1);
	}
	d->sh_ln = command_struct(d->line, d);
	if (d->sh_ln)
	{
		executer(d);
		free_shell_line(d->sh_ln);
		d->sh_ln = NULL;
	}
	free(d->line);
	d->line = NULL;
	return (0);
}
