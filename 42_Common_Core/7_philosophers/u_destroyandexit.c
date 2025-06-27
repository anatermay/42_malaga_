/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_destroyandexit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:31:49 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 13:39:48 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_and_exit(t_table *table)
{
	int	index;

	pthread_mutex_destroy(&table->print_mtx);
	pthread_mutex_destroy(&table->death_mtx);
	pthread_mutex_destroy(&table->meal_mtx);
	index = -1;
	while (++index < table->philos_numb)
	{
		pthread_mutex_destroy(&table->forks[index]);
		pthread_mutex_destroy(&table->philos[index].meal_mutex);
	}
	exit(1);
}
