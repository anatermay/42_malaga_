/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:58:49 by aternero          #+#    #+#             */
/*   Updated: 2025/06/27 12:44:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ** START ** ............................................................. */

// ** ...................................................................... ** 
// **                         H E A D E R   F I L E                          ** 
// **                             ~ AnaTerMay ~                              ** 
// **                               @aternero                                ** 
// ** ...................................................................... ** 

#ifndef PHILO_H
# define PHILO_H

// **LIBRARIES** ............................................................ */

# include <errno.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// ** SYMBOLIC CONSTANTS ** ................................................. */

# define MAX 200

	// ** BOOLS **
# define TRUE 1
# define FALSE 0
# define CORRECT 1
# define ERROR 0

	// ** ERROR MESSAGE **
	// ARGUMENTS PARSING
# define ERR_ARG "Error: Invalid arguments.\n"

	// ** PHILOS' MESSAGE **
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEATH "died\n"

// ** STRUCTURES ** ......................................................... */

typedef struct s_time
{
	long			sec;
	long			usec;
}					t_time;

typedef struct s_table	t_table;

typedef struct s_philo
{
	long			id;
	long			meals;
	bool			death;
	bool			finished;
	long			last_meal_time;
	long			start_time;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
}					t_philo;

typedef struct s_table
{
	long			philos_numb;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			must_eat;
	bool			argv_5;
	long			died;
	long			finished;
	long			start_time;
	t_philo			philos[MAX];
	pthread_t		moiras;
	pthread_mutex_t	forks[MAX];
	pthread_mutex_t	death_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	meal_mtx;
}					t_table;

// ** FUNCTIONS ** .......................................................... */

	//	** ARGUMENT PARSING
int		argument_parsing(int argc, char **argv);
	//	** INIT TABLE
void	init_table(t_table *table, char **argv);
	//	** INIT PHILOS
void	init_philos(t_table *table);
	//	** THREADS
void	threads(t_table *table, t_philo *philos);
	//	** AGORA
void	*agora(void *data);
	//	** GUARD
void	*guard(void *data);

// ** LIBRARY FUNCTIONS ** .................................................. */

	//	** ATOI & ATOL
int		ft_atoi(char *str);
long	ft_atol(char *str);
	//	** CHARACTER CHECKS
int		ft_isdigit(char c);
int		ft_isspace(char c);
	//	** STRING COMPARISON
int		ft_strcmp(const char *s1, const char *s2);

// ** UTILS ** .............................................................. */

	//	** DESTROY AND EXIT
void	destroy_and_exit(t_table *table);
	//	** IS DEATH
int		is_death(t_table *table, t_philo *philos);
	//	** PRINT
void	print_status(t_philo *philo, char *status);
	//	** TIME
long	chronos_gettime(void);
void	ft_usleep(long usec);

#endif

// ** THE END ** ............................................................ */
