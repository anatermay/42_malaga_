/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_isdeath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:49:40 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 16:22:41 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_death_1(t_table *table, t_philo *philos, long current)
{
	pthread_mutex_lock(&table->death_mtx);
	if (table->died == 0)
	{
		philos->death = TRUE;
		table->died++;
		pthread_mutex_unlock(&table->death_mtx);
		pthread_mutex_lock(&table->print_mtx);
		printf("%ld %ld %s", current - philos->start_time, philos->id, DEATH);
		pthread_mutex_unlock(&table->print_mtx);
		return (TRUE);
	}
	pthread_mutex_unlock(&table->death_mtx);
	return (FALSE);
}

int	is_death(t_table *table, t_philo *philos)
{
	long	current;
	long	last_meal;

	pthread_mutex_lock(&table->death_mtx);
	if (table->died > 0)
	{
		pthread_mutex_unlock(&table->death_mtx);
		return (TRUE);
	}
	pthread_mutex_unlock(&table->death_mtx);
	current = chronos_gettime();
	pthread_mutex_lock(&philos->meal_mutex);
	last_meal = philos->last_meal_time;
	pthread_mutex_unlock(&philos->meal_mutex);
	if (current - last_meal >= table->die_time)
		return (is_death_1(table, philos, current));
	return (FALSE);
}
