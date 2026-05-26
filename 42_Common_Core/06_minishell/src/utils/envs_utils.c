/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	update_existing_env(t_envs *tmp, char *value)
{
	free(tmp->value);
	if (value != NULL)
	{
		tmp->value = ft_strdup(value);
		tmp->has_value = 1;
	}
	else
	{
		tmp->value = ft_strdup("");
		tmp->has_value = 0;
	}
}

static t_envs	*create_new_env(char *name, char *value, t_data *d)
{
	t_envs	*new_env;

	new_env = salloc(sizeof(t_envs), d);
	new_env->name = ft_strdup(name);
	if (value != NULL)
	{
		new_env->value = ft_strdup(value);
		new_env->has_value = 1;
	}
	else
	{
		new_env->value = ft_strdup("");
		new_env->has_value = 0;
	}
	new_env->next = NULL;
	return (new_env);
}

char	*ft_getenv(char *name, t_data *d)
{
	t_envs	*tmp;

	tmp = d->envs;
	if (name == NULL || d == NULL || d->envs == NULL)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_setenv(char *name, char *value, t_data *d)
{
	t_envs	*tmp;
	t_envs	*new_env;

	if (name == NULL || d == NULL)
		return ;
	tmp = d->envs;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			update_existing_env(tmp, value);
			return ;
		}
		tmp = tmp->next;
	}
	new_env = create_new_env(name, value, d);
	if (d->envs == NULL)
		d->envs = new_env;
	else
	{
		tmp = d->envs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_env;
	}
}
