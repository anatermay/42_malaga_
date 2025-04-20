/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_detective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:58:53 by aternero          #+#    #+#             */
/*   Updated: 2025/04/10 14:16:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

t_point	find_the_player(char **map)
{
	t_point	point;

	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == 'P')
				return (point);
			point.x++;
		}
		point.y++;
	}
	return (point);
}

int	elements_calculator(char **map, char c)
{
	t_point	point;
	int		count;

	count = 0;
	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == c)
				count++;
			point.x++;
		}
		point.y++;
	}
	return (count);
}
