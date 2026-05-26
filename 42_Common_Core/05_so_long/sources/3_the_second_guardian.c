/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_the_second_guardian.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:50:59 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 12:45:27 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

char	**mapdup(t_map *map)
{
	t_map	*temporal;
	char	**ber;
	int		index;

	temporal = map;
	ber = (char **)malloc(sizeof(char *) * (map_length(map) + 1));
	if (!ber)
		return (NULL);
	index = 0;
	while (map != NULL)
	{
		ber[index] = ft_strdup(map->ber);
		if (!ber[index])
		{
			free_map(ber, strlen_double(ber));
			return (NULL);
		}
		index++;
		map = map->next;
	}
	map = temporal;
	ber[index] = NULL;
	return (ber);
}

int	is_there_all_important_elements(t_map *map)
{
	if (elements_calculator_t(map, 'C') > 0
		&& elements_calculator_t(map, 'E') == 1
		&& elements_calculator_t(map, 'P') == 1)
	{
		map_error("All the important elements are present.", 1, 0);
		return (TRUE);
	}
	ft_printf("Please, provide a valid map\n\tERROR: ");
	if (elements_calculator_t(map, 'C') == 0)
		ft_printf("Insufficient number of tokens. (C)\n");
	if (elements_calculator_t(map, 'E') != 1)
		ft_printf("Incorrect number of exits. (E)\n");
	if (elements_calculator_t(map, 'P') != 1)
		ft_printf("Incorrect number of player's position (P).\n");
	ft_printf("\t\t\t\t\t\t\t\t\t\t\t\t. . . KO\n\t\t\t\t\t\t\t\t\t\t\t\t");
	ft_printf(". . . STOP '>.<\n\t\t\t\t\t\tYou can't play");
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
			return (fenced_map("This map is NOT surrounded by walls (1).", 0));
		aux = aux->next;
	}
	aux = *map;
	if (is_it_fenced_continue(aux->ber, strlen_sl(aux->ber)) == FALSE)
		return (fenced_map("This map is NOT surrounded by walls (1).", 0));
	while (aux->next)
		aux = aux->next;
	if (is_it_fenced_continue(aux->ber, strlen_sl(aux->ber)) == FALSE)
		return (fenced_map("This map is NOT surrounded by walls (1).", 0));
	map_error("The map is surrounded by walls.", 1, 0);
	return (TRUE);
}

int	mapval_content(t_map *map)
{
	char	**ber;
	int		x;

	map_error("The map is rectangle.", 1, 0);
	if (is_it_fenced(&map) == FALSE)
		return (FALSE);
	ber = mapdup(map);
	if (ber == NULL)
	{
		free_t_map(&map);
		return (FALSE);
	}
	if (is_there_all_important_elements(map) == FALSE
		|| flood_fill_check(ber) == FALSE)
		return (FALSE);
	x = 0;
	while (ber[x])
	{
		free(ber[x]);
		ber[x] = NULL;
	}
	ber = NULL;
	return (TRUE);
}
