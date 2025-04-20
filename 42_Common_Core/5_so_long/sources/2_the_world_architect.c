/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_the_world_architect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:19:18 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 12:28:15 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"
#include "../resources/libft/libft.h"

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
		return (NULL);
	}
	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
	{
		free(add);
		return (NULL);
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
		if (!map || mapval_rectangle(line, length) == FALSE)
		{
			free(line);
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	if (line)
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
	map_size_reinit(map);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
