/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_leonardo_da_vinci.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:21:57 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:24:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

void	load_image(t_game *game)
{
	game->exit->text = mlx_load_png("./img/ex.png");
	game->floor->text = mlx_load_png("./img/0.png");
	game->pj->fpj_text = mlx_load_png("./img/fpj.png");
	game->pj->lpj_text = mlx_load_png("./img/lpj.png");
	game->pj->rpj_text = mlx_load_png("./img/rpj.png");
	game->tokens->text = mlx_load_png("./img/c.png");
	game->wall->text = mlx_load_png("./img/1.png");
	if (!game->exit->text || !game->floor->text || !game->pj->fpj_text
		|| !game->pj->lpj_text || !game->pj->rpj_text || !game->tokens->text
		|| !game->wall->text)
	{
		map_error("Some PNG didn't load", 0, 0);
		free_game(game);
		exit(FALSE);
	}
}

void	texture_to_image(t_game *game)
{
	game->exit->img = mlx_texture_to_image(game->mlx, game->exit->text);
	game->floor->img = mlx_texture_to_image(game->mlx, game->floor->text);
	game->pj->fpj_img = mlx_texture_to_image(game->mlx, game->pj->fpj_text);
	game->pj->lpj_img = mlx_texture_to_image(game->mlx, game->pj->lpj_text);
	game->pj->rpj_img = mlx_texture_to_image(game->mlx, game->pj->rpj_text);
	game->tokens->img = mlx_texture_to_image(game->mlx, game->tokens->text);
	game->wall->img = mlx_texture_to_image(game->mlx, game->wall->text);
}

void	rendering(t_game *game)
{
	load_image(game);
	texture_to_image(game);
	game->pj->actual = game->pj->fpj_img;
	telesketch(game, 'F');
}
