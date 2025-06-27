/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_isfinished.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:57:44 by aternero          #+#    #+#             */
/*   Updated: 2025/06/25 15:05:34 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_finished(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->death_mtx);
	if (table->argv_5 == FALSE)
	{
		pthread_mutex_unlock(&table->death_mtx);
		return (FALSE);
	}
	if (philo->finished == TRUE)
	{
		pthread_mutex_unlock(&table->death_mtx);
		return (TRUE);
	}
	if (philo->meals >= table->must_eat)
	{
		philo->finished = TRUE;
		pthread_mutex_unlock(&table->death_mtx);
		return (TRUE);
	}
	pthread_mutex_unlock(&table->death_mtx);
	return (FALSE);
}
