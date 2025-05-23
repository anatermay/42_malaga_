/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:47:43 by aternero          #+#    #+#             */
/*   Updated: 2024/11/29 18:59:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	server_error_handling_bonus(int i)
{
	if (i == 0)
	{
		ft_printf("ERROR:\n   Kill failed\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_printf("Error:\n   Sigaction failed\n");
		exit(1);
	}
}

void	server_receptor_bonus(int sig, siginfo_t *info, void *context)
{
	static unsigned char	val = 0;
	static int				bit = 1;
	static int				id = 0;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context ;
	if (sig == SIGUSR1)
		val += 0;
	if (sig == SIGUSR2)
		val += bit;
	bit *= 2;
	if (bit == 256)
	{
		bit = 1;
		if (val == 0)
			if (kill(id, SIGUSR2) == -1)
				server_error_handling_bonus(0);
		if (val != 0)
			write(1, &val, 1);
		val = 0;
	}
	if (kill(id, SIGUSR1) == -1)
		server_error_handling_bonus(0);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = server_receptor_bonus;
	sigemptyset(&action.sa_mask);
	pid = getpid();
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
	{
		server_error_handling_bonus(1);
		return (1);
	}
	ft_print_pid(pid, 1);
	while (1)
		pause();
	return (0);
}
