/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_threads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:37:25 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 16:13:30 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_and_destroy(t_table *table, bool phase)
{
	int	index;

	if (phase == 0)
		ft_printf("ERROR creating threads\n");
	else
		ft_printf("ERROR joining threads\n");
	pthread_mutex_destroy(&table->print_mtx);
	pthread_mutex_destroy(&table->death_mtx);
	pthread_mutex_destroy(&table->meal_mtx);
	index = -1;
	while (++index < table->philos_numb)
	{
		pthread_mutex_destroy(&table->forks[index]);
		pthread_mutex_destroy(&table->philos[index].meal_mutex);
	}
}

static void	threads_join(t_table *table, t_philo *philos)
{
	int	index;

	index = -1;
	while (++index < philos->table->philos_numb)
	{
		if (pthread_join(philos[index].thread, NULL) != 0)
		{
			print_and_destroy(table, 1);
			return ;
		}
	}
	if (pthread_join(table->moiras, NULL) != 0)
		print_and_destroy(table, 1);
}

static void	threads_create(t_table *table, t_philo *philos)
{
	int	index;

	index = -1;
	table->start_time = chronos_gettime();
	pthread_mutex_lock(&table->meal_mtx);
	while (++index < table->philos_numb)
	{
		philos[index].start_time = table->start_time;
		philos[index].last_meal_time = table->start_time;
		if (pthread_create(&philos[index].thread, NULL, &agora,
				&philos[index]) != 0)
		{
			pthread_mutex_unlock(&table->meal_mtx);
			print_and_destroy(table, 0);
			return ;
		}
	}
	if (pthread_create(&table->moiras, NULL, &guard, philos) != 0)
	{
		pthread_mutex_unlock(&table->meal_mtx);
		print_and_destroy(table, 0);
		return ;
	}
	pthread_mutex_unlock(&table->meal_mtx);
}

void	threads(t_table *table, t_philo *philos)
{
	threads_create(table, philos);
	threads_join(table, philos);
}
