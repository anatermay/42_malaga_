/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_parent_pipes(t_data *d)
{
	if (d->pipeline.prev_pipe_read_end != STDIN_FILENO)
		close(d->pipeline.prev_pipe_read_end);
	if (!d->pipeline.is_last)
	{
		close(d->pipeline.current_pipe_write_end);
		d->pipeline.prev_pipe_read_end = d->pipeline.pipefd[0];
	}
	else
		d->pipeline.prev_pipe_read_end = STDIN_FILENO;
}
