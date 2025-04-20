/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:21:23 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:39:06 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

void	move_pj_cnt(t_game *game, t_point actual, t_point new, char dir)
{
	game->world[new.y][new.x] = 'P';
	game->steps++;
	game->dir = dir;
	ft_printf("\n\nMove Number:\t\t\t%d", game->steps);
	if (dir == 'W')
		ft_printf("\t\t\tDirection:\t\tUP\n");
	if (dir == 'A')
		ft_printf("\t\t\tDirection:\t\tLEFT\n");
	if (dir == 'S')
		ft_printf("\t\t\tDirection:\t\tDOWN\n");
	if (dir == 'D')
		ft_printf("\t\t\tDirection:\t\tRIGHT\n");
	if (game->bexit == true)
		img_telesketch(game, 'E', actual, dir);
	else
		img_telesketch(game, '0', actual, dir);
	img_telesketch(game, 'P', new, dir);
}

void	move_pj(t_game *game, t_point actual, t_point new, char dir)
{
	static bool	exit;

	if (game->world[new.y][new.x] == '1')
		return ;
	else if (game->world[new.y][new.x] == 'E')
	{
		if (elements_calculator(game->world, 'C') == 0)
		{
			ft_printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSUCCESS\n");
			mlx_close_window(game->mlx);
			return ;
		}
		exit = true;
	}
	else
		exit = false;
	if (game->bexit == true)
		game->world[actual.y][actual.x] = 'E';
	else
		game->world[actual.y][actual.x] = '0';
	move_pj_cnt(game, actual, new, dir);
	if (exit == true)
		game->bexit = true;
	else
		game->bexit = false;
}

t_point	new_point(t_point actual, char dir)
{
	t_point	new;

	new.y = actual.y;
	new.x = actual.x;
	if (dir == 'W')
		new.y--;
	if (dir == 'A')
		new.x--;
	if (dir == 'S')
		new.y++;
	if (dir == 'D')
		new.x++;
	return (new);
}

void	keyboard_check_continue(mlx_key_data_t key_data, void *date)
{
	t_game	*game;
	t_point	actual;

	game = date;
	actual = find_the_player(game->world);
	if (key_data.key == MLX_KEY_W && mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_pj(game, actual, new_point(actual, 'W'), 'W');
	if (key_data.key == MLX_KEY_A && mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_pj(game, actual, new_point(actual, 'A'), 'A');
	if (key_data.key == MLX_KEY_D && mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_pj(game, actual, new_point(actual, 'D'), 'D');
	if (key_data.key == MLX_KEY_S && mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_pj(game, actual, new_point(actual, 'S'), 'S');
}

void	keyboard_check(mlx_key_data_t key_data, void *date)
{
	t_game	*game;
	t_point	actual;

	game = date;
	actual = find_the_player(game->world);
	keyboard_check_continue(key_data, date);
	if (key_data.key == MLX_KEY_UP
		&& mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_pj(game, actual, new_point(actual, 'W'), 'W');
	if (key_data.key == MLX_KEY_LEFT
		&& mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_pj(game, actual, new_point(actual, 'A'), 'A');
	if (key_data.key == MLX_KEY_RIGHT
		&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_pj(game, actual, new_point(actual, 'D'), 'D');
	if (key_data.key == MLX_KEY_DOWN
		&& mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_pj(game, actual, new_point(actual, 'S'), 'S');
	if (key_data.key == MLX_KEY_ESCAPE
		&& mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
}
