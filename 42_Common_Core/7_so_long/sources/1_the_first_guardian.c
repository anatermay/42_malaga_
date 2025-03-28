/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_the_first_guardian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:23:33 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:46:25 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

/*
 * This file contains the implementation of functions for validating the map
 * and counting specific elements in the so_long game.
 * 
 * The main features of this code include:
 * - elements_calculator: A function to count the occurrences of a specific
 *   character in the map.
 * - mapval_rectangle: A function to check if the map is a rectangle and
 *   contains valid characters.
 * - mapval_ber: A function to validate the map file extension.
 * - map_validator: The main function that validates the map file and its
 *   contents.
 * 
 * Usage:
 * - These functions are used internally by the so_long game to ensure the
 *   map is valid and meets the required format before starting the game.
 * 
 * Dependencies:
 * - This file depends on the so_long.h header file for type definitions and
 *   function declarations.
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */

int	elements_calculator(t_map *map, char c)
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
	return (TRUE);
}

int	mapval_ber(char *argv)
{
	int	index;

	index = 0;
	while (argv[index] != '\0')
	{
		if (argv[index] == '.')
		{
			if (argv[index + 1] == 'b' && argv[index + 2] == 'e'
				&& argv[index + 3] == 'r' && !argv[index + 4])
			{
				map_error("The map is in the valid format.", 1, 0);
				return (TRUE);
			}
		}
		index++;
	}
	putstr_sl("It's necessary a map with '.ber' extension as an argument.\n");
	map_error("\tUsage: ./so_long [map.ber]\n", 0, 0);
	return (FALSE);
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
		return (FALSE);
	putstr_sl("\n\t\t\t\t\t\t¡¡¡You CAN play!!!");
	free_map(map);
	return (TRUE);
}
