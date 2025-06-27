/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env_exists(char *name, t_data *d)
{
	t_envs	*tmp;

	tmp = d->envs;
	if (name == NULL || d == NULL || d->envs == NULL)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	remove_env_node(t_envs *tmp, t_envs *prev, t_data *d)
{
	if (prev)
		prev->next = tmp->next;
	else
		d->envs = tmp->next;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
}

void	ft_unsetenv(char *name, t_data *d)
{
	t_envs	*tmp;
	t_envs	*prev;

	if (name == NULL || d == NULL)
		return ;
	tmp = d->envs;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			remove_env_node(tmp, prev, d);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

static void	swap_env_nodes(t_envs *tmp, t_envs *next)
{
	char	*temp_name;
	char	*temp_value;
	int		temp_has_value;

	temp_name = tmp->name;
	temp_value = tmp->value;
	temp_has_value = tmp->has_value;
	tmp->name = next->name;
	tmp->value = next->value;
	tmp->has_value = next->has_value;
	next->name = temp_name;
	next->value = temp_value;
	next->has_value = temp_has_value;
}

void	sort_envs(t_data *d)
{
	t_envs	*tmp;
	t_envs	*next;

	tmp = d->envs;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (ft_strcmp(tmp->name, next->name) > 0)
			{
				swap_env_nodes(tmp, next);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
}
