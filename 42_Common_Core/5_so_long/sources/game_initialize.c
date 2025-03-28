/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:24:17 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 11:29:13 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

t_game	*game_initialize(char *argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (FALSE);
	game->map = mapval_gnl(argv, game->map, 1);
	if (!game->map)
	{
		free(game);
		return (FALSE);
	}
	game->player = (t_object *)malloc(sizeof(t_object));
	if (!game->player)
	{
		free_game(game);
		return (FALSE);
	}
	return (game);
}
