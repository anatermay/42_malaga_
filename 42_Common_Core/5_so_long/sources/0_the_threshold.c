/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_the_threshold.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:51:06 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:45:22 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

/*
 * This file contains the implementation of functions for finding the player's
 * position in the map and validating the map file for the so_long game.
 * 
 * The main features of this code include:
 * - find_the_player: A function to locate the player's position in the map.
 * - main: The main function that validates the map file and initializes the
 * 	 game.
 * 
 * Usage:
 * - The find_the_player function is used internally by the so_long game to
 *   determine the starting position of the player.
 * - The main function is the entry point of the program, which takes the map
 *   file as an argument, validates it, and starts the game if valid.
 * 
 * Dependencies:
 * - This file depends on the so_long.h header file for type definitions and
 *   function declarations.
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */

t_point	find_the_player(t_map *map)
{
	t_point	point;

	point.y = 0;
	while (map)
	{
		point.x = 0;
		while (map->ber[point.x])
		{
			if (map->ber[point.x] == 'P')
				return (point);
			point.x++;
		}
		point.y++;
		map = map->next;
	}
	return (point);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (map_validator(argv[1]) == FALSE)
			return (FALSE);
		//mlx_game_init(argv[1]);
	}
	else
		map_error("Introduce the correct number of arguments", 0, 1);
	return (0);
}
