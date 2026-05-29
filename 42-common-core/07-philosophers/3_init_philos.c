/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:56:29 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 16:12:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_table *table)
{
	int			index;

	index = -1;
	while (++index < table->philos_numb)
	{
		table->philos[index].id = index + 1;
		table->philos[index].meals = 0;
		table->philos[index].last_meal_time = 0;
		table->philos[index].death = FALSE;
		table->philos[index].finished = FALSE;
		table->philos[index].start_time = 0;
		table->philos[index].table = table;
		table->philos[index].left_fork = &table->forks[index];
		if (index == table->philos_numb - 1)
			table->philos[index].right_fork = &table->forks[0];
		else
			table->philos[index].right_fork = &table->forks[index + 1];
		if (pthread_mutex_init(&table->philos[index].meal_mutex, NULL) != 0)
		{
			ft_printf("Error initializing philosopher meal mutex\n");
			return ;
		}
	}
}
