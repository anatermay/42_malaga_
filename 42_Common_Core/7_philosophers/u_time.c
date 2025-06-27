/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:39:52 by aternero          #+#    #+#             */
/*   Updated: 2025/06/27 13:52:14 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	chronos_gettime(void)
{
	struct timeval	time;
	long			ret_time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	ret_time = time.tv_sec * (uint64_t)1000 + time.tv_usec / 1000;
	return (ret_time);
}

void	ft_usleep(long usec)
{
	long	elapsed;
	long	start;
	long	remaining;

	start = chronos_gettime();
	while (42)
	{
		elapsed = chronos_gettime() - start;
		if (elapsed >= usec)
			break ;
		remaining = usec - elapsed;
		if (remaining > 1000)
			usleep(500);
		else
			usleep(50);
	}
}
