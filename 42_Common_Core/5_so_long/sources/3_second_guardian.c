/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_second_guardian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:50:59 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:49:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

/*
 * This file contains the implementation of functions for duplicating the map,
 * checking for important elements, and validating the map's structure in the
 * so_long game.
 * 
 * The main features of this code include:
 * - mapdup: A function to create a duplicate of the map.
 * - is_there_all_important_elements: A function to check if all necessary
 *   elements (collectables, exits, and player position) are present in the map.
 * - is_it_fenced: A function to check if the map is surrounded by walls.
 * - mapval_content: A function to validate the map's content and structure.
 * 
 * Usage:
 * - These functions are used internally by the so_long game to ensure the
 *   map is valid and meets the required format before starting the game.
 * 
 * Dependencies:
 * - This file depends on the so_long.h header file for type definitions and
 *   function declarations.
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */

char	**mapdup(t_map *map)
{
	t_map	*aux;
	char	**ber;
	int		y;

	y = 0;
	aux = map;
	while (aux)
	{
		y++;
		aux = aux->next;
	}
	ber = (char **)malloc(sizeof(char *) * (y + 1));
	if (!ber)
		return (NULL);
	y = 0;
	while (map)
	{
		ber[y] = ft_strdup(map->ber);
		y++;
		map = map->next;
	}
	ber[y] = NULL;
	return (ber);
}

int	is_there_all_important_elements(t_map *map)
{
	if (elements_calculator(map, 'C') > 0 && elements_calculator(map, 'E') == 1
		&& elements_calculator(map, 'P') == 1)
	{
		map_error("All the important elements are present.", 1, 0);
		return (TRUE);
	}
	putstr_sl("Please, provide a valid map\n\tERROR: ");
	if (elements_calculator(map, 'C') == 0)
		putstr_sl("Insufficient number of collectables. (C)\n");
	if (elements_calculator(map, 'E') != 1)
	{
		if (elements_calculator(map, 'C') == 0)
			putstr_sl("\tERROR: ");
		putstr_sl("Incorrect number of exits. (E)\n");
	}
	if (elements_calculator(map, 'P') != 1)
	{
		if (elements_calculator(map, 'C') == 0
			|| elements_calculator(map, 'E') != 1)
			putstr_sl("\tERROR: ");
		putstr_sl("Incorrect number of player's position (P).\n");
	}
	putstr_sl("\t\t\t\t\t\t\t\t\t\t\t\t. . . KO\n\t\t\t\t\t\t\t\t\t\t\t\t");
	putstr_sl(". . . SORRY! '>.<\n\t\t\t\t\t\tYou can't play");
	return (FALSE);
}

int	is_it_fenced_continue(char *ber, int size_x)
{
	int	index;

	index = 0;
	while (index < size_x)
	{
		if (ber[index] != '1')
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	is_it_fenced(t_map **map)
{
	t_map	*aux;

	aux = *map;
	while (aux)
	{
		if (aux->ber[0] != '1' || aux->ber[aux->point.x - 1] != '1')
			return (FALSE);
		aux = aux->next;
	}
	aux = *map;
	if (is_it_fenced_continue(aux->ber, aux->point.x) == FALSE)
		return (FALSE);
	while (aux->next)
		aux = aux->next;
	if (is_it_fenced_continue(aux->ber, aux->point.x) == FALSE)
		return (FALSE);
	map_error("The map is surrounded by walls.", 1, 0);
	return (TRUE);
}

int	mapval_content(t_map *map)
{
	char	**ber;
	int		x;

	map_error("The map is rectangle.", 1, 0);
	if (is_it_fenced(&map) == FALSE)
	{
		map_error("This map is NOT surrounded by walls (1).", 0, 0);
		return (FALSE);
	}
	ber = mapdup(map);
	if (is_there_all_important_elements(map) == FALSE
		|| flood_fill_check(ber) == FALSE)
		return (FALSE);
	x = 0;
	while (ber[x])
	{
		free(ber[x]);
		ber[x] = NULL;
	}
	free(ber);
	ber = NULL;
	return (TRUE);
}

/* else if (all_neccesary_elements(map) == TRUE)
	map_error("The map contains all the neccesary elements.", 1, 0);
else
	free_map(map); */