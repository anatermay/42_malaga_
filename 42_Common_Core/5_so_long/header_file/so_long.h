/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:03 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 13:39:11 by aternero         ###   ########.fr       */
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
# include "../resources/libft/libft.h"
# include "../resources/ft_printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
//# include "./MLX42/MLX42.h"

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

typedef struct s_player
{
	mlx_texture_t	*fpj_text;
	mlx_texture_t	*lpj_text;
	mlx_texture_t	*rpj_text;
	mlx_image_t		*fpj_img;
	mlx_image_t		*lpj_img;
	mlx_image_t		*rpj_img;
	mlx_image_t		*actual;
	t_point			point;
}	t_player;

typedef struct s_map
{
	char			*ber;
	char			*ber_path;
	t_point			point;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_tokens
{
	mlx_texture_t	*text;
	mlx_image_t		*img;
	t_point			point;
	int				count;
	int				open;
	int				total;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	*pj;
	t_tokens	*exit;
	t_tokens	*floor;
	t_tokens	*tokens;
	t_tokens	*wall;
	char		*ber_path;
	char		**world;
	char		dir;
	int			in_move;
	int			steps;
	int			taken;
	bool		bexit;
}	t_game;

// **FUNCTIONS**

// ***The Threshold***
int			main(int argc, char **argv);

// ***The First Guardian***
int			elements_calculator_t(t_map *map, char c);
int			mapval_rectangle(char *line, int length);
int			mapval_ber(char *argv);
int			map_validator(char *argv);

// *** The World Architect***
t_map		*map_size_reinit(t_map *map);
t_map		*map_init(t_map *map, char *add, char *argv);
t_map		*mapval_gnl_continue_2(t_map *map, char *argv, int fd);
int			mapval_gnl_continue(char *argv, int print);
t_map		*mapval_gnl(char *argv, t_map *map, int print);

// *** The Second Guardian***
char		**mapdup(t_map *map);
int			mapval_content(t_map *map);
int			is_it_fenced(t_map **map);
int			is_it_fenced_continue(char *ber, int size_x);
int			is_there_all_important_elements(t_map *map);

// *** The Maze Explorer***
t_point		player_init_position(char **map);
char		**fill_check(char **map, t_point table, t_point init);
int			flood_fill_check(char **map);
int			is_all_filled(char **map);

// *** The Windows Engineer***
t_game		*game_building(char *map);
void		mlx_game_init(char *map);

// *** Inn's Receptionist ***
t_game		*book_space_for_game(char *map);
t_tokens	*book_tokens(t_game *game, char c);
t_tokens	*add_back(t_tokens **head, t_game *game, t_point point, char c);
t_tokens	*new_token(t_game *game, t_point point, char c);
char		**book_map(t_game *game);

// *** Leonardo Da Vinci***
void		rendering(t_game *game);
void		load_image(t_game *game);
void		texture_to_image(t_game *game);

// *** Detective ***
t_point		find_the_player(char **map);
int			elements_calculator(char **map, char c);

// *** Telesketch **
void		telesketch(t_game *game, char dir);
void		img_telesketch(t_game *game, char c, t_point point, char dir);
void		pj_telesketch(t_game *game, t_point point, char dir);
void		movement_telesketch(t_game *game, t_point point, char dir);

// *** Keyboard ***
void		move_pj_cnt(t_game *game, t_point actual, t_point new, char dir);
void		move_pj(t_game *game, t_point actual, t_point new, char dir);
t_point		new_point(t_point actual, char dir);
void		keyboard_check(mlx_key_data_t key_data, void *date);

// ** AUXILIAR FUNCTIONS **

// MAP
int			fenced_map(char *str, int ok);
int			strlen_double(char **str);
int			strlen_sl(char *str);
int			map_length(t_map *map);
void		map_error(char *str, int ok, int main);
// CLEANING TEAM
void		free_game(t_game *game);
void		free_t_map(t_map **map);
void		free_map(char **map, int length);
void		free_tokens(t_game *game, t_tokens **tokens);
void		free_player(t_game *game, t_player *player);

#endif
