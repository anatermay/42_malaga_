/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_the_windows_engineer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:32:06 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:51:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

/*
 * This file contains the implementation of functions for initializing the
 * game window and handling errors related to the MLX42 library in the so_long
 * game.
 * 
 * The main features of this code include:
 * - mlx_game_init: A function to initialize the game structure and the MLX42
 *   window.
 * - game_initialize: A function to set up the game structure with the map data.
 * - find_the_player: A function to locate the player's position in the map.
 * 
 * Usage:
 * - The mlx_game_init function is used to start the game by initializing the
 *   game structure and creating the game window.
 * 
 * Dependencies:
 * - This file depends on the so_long.h header file for type definitions and
 *   function declarations.
 * - It also depends on the MLX42 library for window management and graphics.
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */

/* void	mlx_game_init(char *argv)
{
	t_game	*game;
	t_point	point;

	game = game_initialize(argv);
	if (!game)
		return ;
	game->player->point = find_the_player(game->map);
	point = game->player->point;
	game->mlx = mlx_init(point.x * 64, point.y * 64, "so_long", TRUE);
	if (!game || !game->mlx)
	{
		map_error("MLX42 initialization has failed.", 0, 0);
		free_game(game);
		exit (FALSE);
	}
	free_game(game);
} */
