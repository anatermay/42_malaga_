/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:56:33 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 15:39:02 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_while(t_data *d)
{
	d->prompt = prompter(d);
	d->line = readline(d->prompt);
	free(d->prompt);
	if (g_signal == S_SIGINT && d->line == NULL)
	{
		d->exit_status = 130;
		g_signal = S_BASE;
	}
	if (d->line && g_signal == S_SIGINT)
		g_signal = S_BASE;
	if (g_signal == S_SIGINT_CMD)
		handle_signal_sigint_cmd(d);
	if (d->line == NULL)
		custom_exit(d, "exit\n", EXIT_SUCCESS);
	parser_and_commander_jaja(d);
	if (d->line[0] == '\0')
	{
		free(d->line);
		d->line = NULL;
	}
	process_input(d);
}

void	loop(t_data *d)
{
	while (42)
	{
		loop_while(d);
	}
}

int	main(int argc, char **argv, char **envs)
{
	t_data	*d;

	d = NULL;
	if (argc > 1 && argv)
		custom_exit(NULL, "Error: Too many arguments", EXIT_FAILURE);
	init_data(&d, envs);
	init_signals();
	print_ascii_art("shellder.txt");
	loop(d);
	free_data(d);
	return (0);
}
