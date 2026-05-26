/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:30:55 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 16:12:24 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex(t_table *table)
{
	int	index;

	index = -1;
	while (++index < table->philos_numb)
	{
		if (pthread_mutex_init(&table->forks[index], NULL) != 0)
		{
			ft_printf("Error initializing fork mutex %d\n", index);
			return ;
		}
	}
	if (pthread_mutex_init(&table->death_mtx, NULL) != 0
		|| pthread_mutex_init(&table->meal_mtx, NULL) != 0
		|| pthread_mutex_init(&table->print_mtx, NULL) != 0)
	{
		ft_printf("Error initializing mutexes\n");
		return ;
	}
}

static void	argv_to_table(t_table *table, char **argv)
{
	table->philos_numb = ft_atol(argv[1]);
	table->die_time = ft_atol(argv[2]);
	table->eat_time = ft_atol(argv[3]);
	table->sleep_time = ft_atol(argv[4]);
	if (argv[5])
	{
		table->must_eat = ft_atol((argv[5]));
		table->argv_5 = TRUE;
	}
	else
	{
		table->must_eat = -1;
		table->argv_5 = FALSE;
	}
}

void	init_table(t_table *table, char **argv)
{
	if (!table)
		return ;
	argv_to_table(table, argv);
	table->finished = 0;
	table->died = 0;
	table->start_time = chronos_gettime();
	init_mutex(table);
}
