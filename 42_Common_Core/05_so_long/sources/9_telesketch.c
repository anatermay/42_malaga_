/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_telesketch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:51:05 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:24:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

void	movement_telesketch(t_game *game, t_point pt, char dir)
{
	if ((dir == 'W' || dir == 'S') && game->pj->fpj_img)
		mlx_image_to_window(game->mlx, game->pj->fpj_img, pt.x * 64, pt.y * 64);
	if (dir == 'A' && game->pj->lpj_img)
		mlx_image_to_window(game->mlx, game->pj->lpj_img, pt.x * 64, pt.y * 64);
	if (dir == 'D' && game->pj->rpj_img)
		mlx_image_to_window(game->mlx, game->pj->rpj_img, pt.x * 64, pt.y * 64);
}

void	pj_telesketch(t_game *game, t_point pt, char dir)
{
	if ((dir == 'W' || dir == 'S' || dir == 'A' || dir == 'D')
		&& game->steps > 0)
		movement_telesketch(game, pt, dir);
	else
		mlx_image_to_window(game->mlx, game->pj->actual, pt.x * 64, pt.y * 64);
}

void	img_telesketch(t_game *game, char c, t_point pt, char dir)
{
	mlx_image_to_window(game->mlx, game->floor->img, pt.x * 64, pt.y * 64);
	if (c == '1' && game->wall->img)
		mlx_image_to_window(game->mlx, game->wall->img, pt.x * 64, pt.y * 64);
	if (c == 'C' && game->tokens->img)
		mlx_image_to_window(game->mlx, game->tokens->img, pt.x * 64, pt.y * 64);
	if (c == 'E' && game->exit->img)
		mlx_image_to_window(game->mlx, game->exit->img, pt.x * 64, pt.y * 64);
	if (c == 'P')
	{
		pj_telesketch(game, pt, dir);
		return ;
	}
}

void	telesketch(t_game *game, char dir)
{
	t_point	point;
	int		y;
	int		x;

	y = -1;
	while (game->world[++y])
	{
		x = -1;
		while (game->world[y][++x] && x < strlen_sl(game->world[0]))
		{
			point.y = y;
			point.x = x;
			img_telesketch(game, game->world[y][x], point, dir);
		}
	}
	pj_telesketch(game, find_the_player(game->world), dir);
}
