/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:03 by aternero          #+#    #+#             */
/*   Updated: 2025/03/13 13:50:48 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PROGRAM "so_long"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "../resources/LIBFT/libft.h"
//# include "../MLX42/include/MLX42/MLX42.h"
//# include "../MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4069
# endif

// **RETURN**

# define FALSE 0
# define TRUE 1

# define MAP_ERROR "Map error"

# define MAPVAL_GNL_ERROR "Map file not open\n\tKO"
# define MAP_VALIDATOR_ERROR "Map is invalid\n\tKO"

//	**STRUCTURES**

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char			*ber;
	char			*ber_path;
	t_point			point;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_object
{
	t_point	point;
}	t_object;

typedef struct s_game
{
	//mlx_t			*mlx;
	t_map			*map;
	t_object		*player;
}	t_game;

// **FUNCTIONS**

/* **[MECHANICS:] Characters ARC**
	Movimiento del jugador y colisiones.*/

/* **[RESOURCES:] Editorial**
	Manejo de errores y mensajes en consola.*/
void	free_game(t_game *game);
void	free_map(t_map *map);

/* **[RESOURCES:] Epilogue**
	Libera memoria y cierra el juego correctamente.*/

/* **[RESOURCES:] Foot Notes**
	Funciones auxiliares*/
void	map_error(char *str, int ok, int main);
int		strlen_sl(char *str);
int		map_length(t_map *map);
void	putstr_sl(char *str);

/* **[RESOURCES:] Ft Printf**
	Implementación  personalizada  de  la  función  printf*/

/* **[GAME:] Game Initialize**
	*/
t_game	*game_initialize(char *argv);

/* **[GRAPHICS:] Illustrations**
	Manejo de texturas, carga de sprites y renderizado en pantalla.*/

/* **[GRAPHICS:] Illustrator**
	_flood_fill_*/

/* **[RESOURCES:] LIBFT**
	Una biblioteca de funciones básicas en C para reutilización eficiente.*/
/* size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
 */

/*	**[MLX:] MLX42 Init**
*/
void	mlx_game_init(char *argv);

/* **[MECHANICS:] Narrative**
	Control del flujo del juego, detección de victoria o derrota.*/

/* **[GRAPHICS:] Perspective**
	Calcula posiciones en la pantalla y actualiza los elementos del juego.*/
t_point	find_the_player(t_map *map);

/* **[RESOURCES:] Plot Twist**
	Algoritmos para encontrar caminos válidos en el mapa*/

/* **[MECHANICS:] Turning Pages**
	Manejo de eventos (teclas, cierre de ventana).*/

/* **[WORLDBUILDING:] Worldbuilding Content Validator**
	Manejo del mapa: validador de contenido*/
int		mapval_content(t_map *map);
int		is_all_filled(char **map);
char	**fill_check(char **map, t_point table, t_point init);
t_point	player_init_position(char **map);
int		recalculate_total_number(char **map, char c);
int		flood_fill_check(char **map);

/* **[WORLDBUILDING:] Worldbuilding Init**
	Manejo del mapa: lectura e inicialización
	*/
t_map	*mapval_gnl(char *argv, t_map *map, int print);
int		mapval_gnl_continue(char *argv, int print);
t_map	*map_init(t_map *map, char *add, char *argv);
t_map	*map_size_reinit(t_map *map);

/* **[WORLDBUILDING:] Worldbuilding Validator**
	Manejo del mapa: verificaciones*/
int		map_validator(char *argv);
int		mapval_ber(char *argv);
int		mapval_rectangle(char *line, int length);
int		elements_calculator(t_map *map, char c);

#endif

/*
ES:	Contiene las estructuras, macros, includes y prototipos de funciones.
*/

/*
Quiero un comentario sobre el contenido de este archivo usando /* como en el ejemplo-template, pero respetando la anchura del encabezado y completando los gaps indicados entre []

"""
/*
 * This file contains the implementation of [describe the main functionality
 * or purpose of the code].
 * 
 * The main features of this code include:
 * - [Feature 1]: [Brief description of feature 1]
 * - [Feature 2]: [Brief description of feature 2]
 * - [Feature 3]: [Brief description of feature 3]
 * 
 * Usage:
 * - [Describe how to use the code, if applicable]
 * 
 * Dependencies:
 * - [List any external libraries or dependencies required]
 * 
 * Author: AnaTerMay
 * Date: 13/03/2025
 */
"""
*/