/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	handle_signal_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			return (131);
		else if (WTERMSIG(status) == SIGINT)
			return (130);
		else
			return (128 + WTERMSIG(status));
	}
	else if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

static int	handle_interrupted_status(int status)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
		return (131);
	else
		return (130);
}

void	wait_for_children(t_data *d)
{
	int	status;
	int	i;
	int	last_exit_status;

	last_exit_status = 0;
	i = 0;
	while (i < d->pipeline.cmd_count)
	{
		waitpid(d->pipeline.pids[i], &status, 0);
		if (g_signal == S_SIGINT_CMD)
			last_exit_status = handle_interrupted_status(status);
		else
			last_exit_status = handle_signal_status(status);
		i++;
	}
	d->exit_status = last_exit_status;
	g_signal = S_BASE;
}
