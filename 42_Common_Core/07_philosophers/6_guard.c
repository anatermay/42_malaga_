/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_guard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:54:54 by aternero          #+#    #+#             */
/*   Updated: 2025/06/27 14:26:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	guard_1(t_table *table)
{
	pthread_mutex_lock(&table->meal_mtx);
	if (table->finished >= table->philos_numb)
	{
		pthread_mutex_unlock(&table->meal_mtx);
		pthread_mutex_lock(&table->death_mtx);
		table->finished = 1;
		pthread_mutex_unlock(&table->death_mtx);
		return (FALSE);
	}
	pthread_mutex_unlock(&table->meal_mtx);
	return (TRUE);
}

void	*guard(void *data)
{
	t_philo	*philo;
	t_table	*table;
	int		index;

	philo = (t_philo *)data;
	table = philo->table;
	while (1)
	{
		index = -1;
		while (++index < table->philos_numb)
		{
			if (is_death(table, &table->philos[index]) == TRUE)
				return (NULL);
		}
		if (table->argv_5)
		{
			if (guard_1(table) == FALSE)
				return (NULL);
		}
		ft_usleep(10);
	}
	return (NULL);
}
