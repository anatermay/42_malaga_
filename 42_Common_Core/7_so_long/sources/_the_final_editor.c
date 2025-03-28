/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _the_final_editor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:30:34 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:44:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

/*
 * This file contains the implementation of functions for freeing memory
 * used by the game and map structures in the so_long game.
 * 
 * The main features of this code include:
 * - free_game: A function to free the memory allocated for the game structure.
 * - free_map: A function to free the memory allocated for the map structure.
 * 
 * Usage:
 * - These functions are used internally by the so_long game to manage memory
 *   and ensure proper cleanup of resources.
 * 
 * Dependencies:
 * - This file depends on the so_long.h header file for type definitions and
 *   function declarations.
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */

void	free_game(t_game *game)
{
	t_game	*lst;

	lst = game;
	if (!lst)
		return ;
	free_map(lst->map);
	free(lst);
}

void	free_map(t_map *map)
{
	t_map	*stack;
	t_map	*auxiliar;

	stack = map;
	if (!stack)
		return ;
	while (stack)
	{
		auxiliar = stack->next;
		if (stack->ber)
			free(stack->ber);
		free(stack);
		stack = auxiliar;
	}
}
