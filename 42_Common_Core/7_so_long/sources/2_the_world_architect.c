/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_the_world_architect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:19:18 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:47:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"
#include "../resources/LIBFT/libft.h"

/*
 * This file contains the implementation of functions for initializing and
 * validating the map structure in the so_long game.
 * 
 * The main features of this code include:
 * - map_size_reinit: A function to reinitialize the map size and set the
 *   coordinates for each point in the map.
 * - map_init: A function to initialize a new map node and add it to the map
 *   linked list.
 * - mapval_gnl_continue_2: A function to read the map file line by line,
 *   validate each line, and initialize the map structure.
 * - mapval_gnl_continue: A function to open the map file and handle errors.
 * - mapval_gnl: A function to manage the overall process of reading and
 *   validating the map file.
 * 
 * Usage:
 * - These functions are used internally by the so_long game to initialize
 *   and validate the map structure before starting the game.
 * 
 * Dependencies:
 * - This file depends on the so_long.h header file for type definitions and
 *   function declarations.
 * - It also depends on the LIBFT library for additional utility functions.
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */

t_map	*map_size_reinit(t_map *map)
{
	int	y;

	y = 0;
	while (map)
	{
		map->point.y = y;
		map->point.x = strlen_sl(map->ber);
		y++;
		map = map->next;
	}
	return (map);
}

t_map	*map_init(t_map *map, char *add, char *argv)
{
	t_map	*new;
	t_map	*temp;

	if (!add || add[0] == '\0')
	{
		free(add);
		return (FALSE);
	}
	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
	{
		free(add);
		return (FALSE);
	}
	new->ber = add;
	new->ber_path = argv;
	new->next = NULL;
	if (!map)
		return (new);
	temp = map;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (map);
}

t_map	*mapval_gnl_continue_2(t_map *map, char *argv, int fd)
{
	char	*line;
	int		length;

	line = get_next_line(fd);
	if (!line)
	{
		map_error("The map file seams empty.", 0, 0);
		close(fd);
		return (NULL);
	}
	length = strlen_sl(line);
	while (line)
	{
		map = map_init(map, line, argv);
		if (map == FALSE || mapval_rectangle(line, length) == FALSE)
		{
			free(line);
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	map_size_reinit(map);
	free(line);
	return (map);
}

int	mapval_gnl_continue(char *argv, int print)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		map_error("Map file not open", 0, 0);
		return (FALSE);
	}
	if (print == 0)
		map_error("The map is open.", 1, 0);
	return (fd);
}

t_map	*mapval_gnl(char *argv, t_map *map, int print)
{
	int		fd;

	map = NULL;
	fd = mapval_gnl_continue(argv, print);
	if (fd == FALSE)
		return (NULL);
	map = mapval_gnl_continue_2(map, argv, fd);
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}
