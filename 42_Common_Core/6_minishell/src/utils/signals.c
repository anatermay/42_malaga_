/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 17:49:28 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal;

static void	handle_sigint_heredoc(void)
{
	g_signal = S_CANCEL_EXEC;
	write(STDOUT_FILENO, "\n", 1);
}

static void	handle_sigint_base(void)
{
	g_signal = S_SIGINT;
	write(STDOUT_FILENO, "\n", 1);
	if (isatty(STDIN_FILENO))
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	handle_sigint_cmd(void)
{
	g_signal = S_SIGINT_CMD;
	write(STDOUT_FILENO, "\n", 1);
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (g_signal == S_CMD)
			handle_sigint_cmd();
		else if (g_signal == S_HEREDOC)
			handle_sigint_heredoc();
		else
			handle_sigint_base();
	}
	else if (sig == SIGQUIT)
	{
		if (g_signal == S_CMD)
		{
			g_signal = S_SIGINT_CMD;
			write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		}
	}
}

void	init_signals(void)
{
	struct sigaction	sa;

	g_signal = S_BASE;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	sigaction(SIGQUIT, &sa, NULL);
}
