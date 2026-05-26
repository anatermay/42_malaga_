/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_atol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:22:49 by aternero          #+#    #+#             */
/*   Updated: 2025/06/27 13:22:09 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		index;
	long	nbr;
	long	sign;

	index = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[index]) == TRUE)
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		nbr = (nbr * 10) + (str[index] - 48);
		index++;
	}
	return (nbr * sign);
}
