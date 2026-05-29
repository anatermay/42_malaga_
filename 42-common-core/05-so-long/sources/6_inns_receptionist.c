/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_inns_receptionist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:19:00 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:26:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

t_tokens	*new_token(t_game *game, t_point point, char c)
{
	t_tokens	*token;

	token = (t_tokens *)malloc(sizeof(t_tokens));
	if (!token)
	{
		free_game(game);
		return (NULL);
	}
	token->total = elements_calculator(game->world, c);
	token->open = 0;
	token->count = 0;
	token->point.x = point.x;
	token->point.y = point.y;
	token->next = NULL;
	return (token);
}

t_tokens	*add_back(t_tokens **head, t_game *game, t_point point, char c)
{
	t_tokens	*new;
	t_tokens	*temp;

	new = new_token(game, point, c);
	if (!new)
		return (NULL);
	if (!*head)
	{
		*head = new;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (*head);
}

t_tokens	*book_tokens(t_game *game, char c)
{
	t_tokens	*head;
	t_point		point;

	head = NULL;
	if (c == '\0' || c == '\n')
		return (NULL);
	point.y = 0;
	while (game->world[point.y])
	{
		point.x = 0;
		while (game->world[point.y][point.x])
		{
			if (game->world[point.y][point.x] == c)
				add_back(&head, game, point, c);
			point.x++;
		}
		point.y++;
	}
	return (head);
}

char	**book_map(t_game *game)
{
	t_map	*map;
	char	**world;
	int		point;

	map = NULL;
	map = mapval_gnl(game->ber_path, map, 0);
	point = 0;
	world = (char **)malloc(sizeof(char *) * (map_length(map) + 1));
	if (!world)
	{
		free_game(game);
		return (NULL);
	}
	while (map)
	{
		world[point] = ft_strdup(map->ber);
		point++;
		map = map->next;
	}
	world[point] = NULL;
	free_t_map(&map);
	return (world);
}

t_game	*book_space_for_game(char *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->ber_path = map;
	game->world = book_map(game);
	game->exit = book_tokens(game, 'E');
	game->bexit = false;
	game->floor = book_tokens(game, '0');
	game->tokens = book_tokens(game, 'C');
	game->taken = elements_calculator(game->world, 'C');
	game->wall = book_tokens(game, '1');
	game->steps = 0;
	game->pj = (t_player *)malloc(sizeof(t_player));
	if (!game->pj)
	{
		free_game(game);
		return (NULL);
	}
	game->pj->point = find_the_player(game->world);
	return (game);
}
