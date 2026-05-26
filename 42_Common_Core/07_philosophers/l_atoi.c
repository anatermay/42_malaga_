/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:27:20 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 12:50:14 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	index;
	int	nbr;
	int	sign;

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
