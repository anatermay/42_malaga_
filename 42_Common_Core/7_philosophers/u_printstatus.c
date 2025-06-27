/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printstatus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:51 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 13:41:40 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	long	current;

	pthread_mutex_lock(&philo->table->print_mtx);
	pthread_mutex_lock(&philo->table->death_mtx);
	if (philo->table->died > 0)
	{
		pthread_mutex_unlock(&philo->table->death_mtx);
		pthread_mutex_unlock(&philo->table->print_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->table->death_mtx);
	current = chronos_gettime();
	printf("%ld %ld %s", current - philo->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
