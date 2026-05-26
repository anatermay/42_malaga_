/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_argument_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:21:31 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 12:50:14 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error(int error)
{
	ft_printf(ERR_ARG);
	if (error == 1)
	{
		ft_printf("Usage: ./philo [number_of_philosophers] [time_to_die] ");
		ft_printf("[time_to_eat] [time_to_sleep]");
		ft_printf(" [number_of_times_each_philosopher_must_eat]\n");
	}
	return (ERROR);
}

static int	valid_arguments(int argc, char **argv)
{
	long	aux;
	int		index;
	int		yndex;

	if (argc < 5 || argc > 6)
		return (ERROR);
	yndex = 0;
	while (argv[++yndex])
	{
		index = -1;
		while (argv[yndex][++index])
		{
			if (ft_isspace(argv[yndex][index]) == FALSE
				&& ft_isdigit(argv[yndex][index]) == FALSE)
				return (ERROR);
		}
		aux = ft_atol(argv[yndex]);
		if (aux < 1 || (yndex == 1 && aux > 200)
			|| (yndex != 1 && aux > INT_MAX))
			return (ERROR);
	}
	return (CORRECT);
}

int	argument_parsing(int argc, char **argv)
{
	if (valid_arguments(argc, argv) == ERROR)
		return (print_error(1));
	return (CORRECT);
}
