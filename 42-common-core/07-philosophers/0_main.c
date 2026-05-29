/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:12:48 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 12:54:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_one_ad_hoc(long time)
{
	ft_printf("0 1 has taken a fork\n");
	printf("%ld 1 died\n", (time + 1));
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argument_parsing(argc, argv) == ERROR)
		return (ERROR);
	if (ft_atoi(argv[1]) == 1)
		return (print_one_ad_hoc(ft_atol(argv[2])));
	init_table(&table, argv);
	init_philos(&table);
	threads(&table, (&table)->philos);
	return (0);
}
