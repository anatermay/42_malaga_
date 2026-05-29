/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_the_windows_engineer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:32:06 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:30:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

t_game	*game_building(char *map)
{
	t_game	*game;
	t_point	size;

	game = book_space_for_game(map);
	if (!game)
	{
		free_game(game);
		exit(FALSE);
	}
	size.y = strlen_double(game->world);
	size.x = ft_strlen(game->world[0]) - 1;
	game->mlx = mlx_init(size.x * 64, size.y * 64, "so_long", FALSE);
	if (!game || !game->mlx)
	{
		map_error("MLX42 failed", 0, 0);
		free_game(game);
		exit(FALSE);
	}
	return (game);
}

void	mlx_game_init(char *map)
{
	t_game	*game;

	game = game_building(map);
	rendering(game);
	mlx_key_hook(game->mlx, keyboard_check, game);
	mlx_loop(game->mlx);
}
