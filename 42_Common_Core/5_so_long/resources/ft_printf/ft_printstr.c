/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:59:03 by aternero          #+#    #+#             */
/*   Updated: 2025/04/12 14:05:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	index;
	int	value;

	index = 0;
	value = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
		value++;
	}
	return (value);
}
