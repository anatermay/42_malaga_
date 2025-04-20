/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendix_cleaning_team.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:30:34 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:21:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

void	free_player(t_game *game, t_player *player)
{
	if (player->fpj_text)
		mlx_delete_texture(player->fpj_text);
	if (player->lpj_text)
		mlx_delete_texture(player->lpj_text);
	if (player->rpj_text)
		mlx_delete_texture(player->rpj_text);
	if (player->fpj_img)
		mlx_delete_image(game->mlx, player->fpj_img);
	if (player->lpj_img)
		mlx_delete_image(game->mlx, player->lpj_img);
	if (player->rpj_img)
		mlx_delete_image(game->mlx, player->rpj_img);
	free(player);
}

void	free_tokens(t_game *game, t_tokens **tokens)
{
	t_tokens	*auxiliar;

	if (!tokens || !*tokens)
		return ;
	while (*tokens)
	{
		auxiliar = (*tokens)->next;
		if ((*tokens)->text)
			mlx_delete_texture((*tokens)->text);
		if ((*tokens)->img)
			mlx_delete_image(game->mlx, (*tokens)->img);
		free(*tokens);
		*tokens = auxiliar;
	}
	*tokens = NULL;
}

void	free_map(char **map, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (map[index])
		{
			free(map[index]);
			map[index] = NULL;
		}
		index++;
	}
	map = NULL;
}

void	free_t_map(t_map **map)
{
	t_map	*auxiliar;

	if (!map || !*map)
		return ;
	while (*map)
	{
		auxiliar = (*map)->next;
		if ((*map)->ber)
		{
			free((*map)->ber);
			(*map)->ber = NULL;
		}
		if (map)
			free(*map);
		(*map) = auxiliar;
	}
	*map = NULL;
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->pj)
		free_player(game, game->pj);
	if (game->exit)
		free_tokens(game, &game->exit);
	if (game->floor)
		free_tokens(game, &game->floor);
	if (game->tokens)
		free_tokens(game, &game->tokens);
	if (game->wall)
		free_tokens(game, &game->wall);
	if (game->world)
		free_map(game->world, strlen_double(game->world));
	free(game);
}
