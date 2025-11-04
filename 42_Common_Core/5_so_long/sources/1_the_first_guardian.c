/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_the_first_guardian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:23:33 by aternero          #+#    #+#             */
/*   Updated: 2025/07/09 16:12:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

int	elements_calculator_t(t_map *map, char c)
{
	int		count;
	int		x;

	count = 0;
	while (map)
	{
		x = 0;
		while (map->ber[x])
		{
			if (map->ber[x] == c)
				count++;
			x++;
		}
		map = map->next;
	}
	return (count);
}

int	mapval_rectangle(char *line, int length)
{
	int	index;

	index = 0;
	if (length < 1)
	{
		map_error("This map could be empty.", 0, 0);
		return (FALSE);
	}
	index = strlen_sl(line);
	if (index != length)
	{
		map_error("The map isn't a rectangle or it has an invalid char.", 0, 0);
		return (FALSE);
	}
	return (TRUE)
}


int	map_validator(char *argv)
{
	t_map	*map;

	map = NULL;
	if (mapval_ber(argv) == FALSE)
		return (FALSE);
	map = mapval_gnl(argv, map, 0);
	if (!map)
		return (FALSE);
	if (mapval_content(map) == FALSE)
	{
		free_t_map(&map);
		return (FALSE);
	}
	free_t_map(&map);
	return (TRUE);
}
