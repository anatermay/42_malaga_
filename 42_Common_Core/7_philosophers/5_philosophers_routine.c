/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philosophers_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:55:14 by aternero          #+#    #+#             */
/*   Updated: 2025/06/26 16:19:05 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = chronos_gettime();
	philo->meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, EAT);
	ft_usleep(philo->table->eat_time);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->table->argv_5 && philo->meals >= philo->table->must_eat)
	{
		pthread_mutex_lock(&philo->table->meal_mtx);
		if (!philo->finished)
		{
			philo->finished = TRUE;
			philo->table->finished++;
		}
		pthread_mutex_unlock(&philo->table->meal_mtx);
	}
	print_status(philo, SLEEP);
	ft_usleep(philo->table->sleep_time);
	print_status(philo, THINK);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id == philo->table->philos_numb)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
	}
}

static int	check_values_1(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->death_mtx);
	if (philos->table->died > 0)
	{
		pthread_mutex_unlock(&philos->table->death_mtx);
		pthread_mutex_unlock(philos->right_fork);
		pthread_mutex_unlock(philos->left_fork);
		return (TRUE);
	}
	pthread_mutex_unlock(&philos->table->death_mtx);
	return (FALSE);
}

static int	check_values_0(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->death_mtx);
	if (philos->table->died > 0)
	{
		pthread_mutex_unlock(&philos->table->death_mtx);
		return (TRUE);
	}
	pthread_mutex_unlock(&philos->table->death_mtx);
	pthread_mutex_lock(&philos->table->meal_mtx);
	if (philos->finished == TRUE)
	{
		pthread_mutex_unlock(&philos->table->meal_mtx);
		return (TRUE);
	}
	pthread_mutex_unlock(&philos->table->meal_mtx);
	if (philos->table->philos_numb == 1)
	{
		pthread_mutex_lock(philos->left_fork);
		print_status(philos, FORK);
		ft_usleep(philos->table->die_time);
		pthread_mutex_unlock(philos->left_fork);
		return (TRUE);
	}
	return (FALSE);
}

void	*agora(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!philo || !philo->table)
		return (NULL);
	pthread_mutex_lock(&philo->table->meal_mtx);
	pthread_mutex_unlock(&philo->table->meal_mtx);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->eat_time / 2);
	while (1)
	{
		if (check_values_0(philo) == TRUE)
			break ;
		take_forks(philo);
		if (check_values_1(philo) == TRUE)
			break ;
		philo_eats(philo);
		if (philo->table->philos_numb % 2 == 1)
			ft_usleep(1);
	}
	return (NULL);
}
