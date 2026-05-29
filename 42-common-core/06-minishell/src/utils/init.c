/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*extract_env_name(char *env_string, t_data *d)
{
	int		len;
	int		j;
	char	*name;

	len = 0;
	while (env_string[len] && env_string[len] != '=')
		len++;
	name = salloc(len + 1, d);
	j = 0;
	while (j < len)
	{
		name[j] = env_string[j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

static char	*extract_env_value(char *env_string, int name_len, t_data *d)
{
	int		value_len;
	int		j;
	int		k;
	char	*value;

	j = name_len + 1;
	value_len = 0;
	while (env_string[j + value_len] && env_string[j + value_len] != '\0')
		value_len++;
	value = salloc(value_len + 1, d);
	k = 0;
	while (k < value_len)
	{
		value[k] = env_string[j + k];
		k++;
	}
	value[k] = '\0';
	return (value);
}

static t_envs	*create_env_node(char *env_string, t_data *d)
{
	t_envs	*tmp;
	int		name_len;

	tmp = salloc(sizeof(t_envs), d);
	tmp->next = NULL;
	tmp->name = extract_env_name(env_string, d);
	name_len = 0;
	while (env_string[name_len] && env_string[name_len] != '=')
		name_len++;
	tmp->value = extract_env_value(env_string, name_len, d);
	tmp->has_value = 1;
	return (tmp);
}

static t_envs	*parse_env(char **envs, t_data *d)
{
	t_envs	*head;
	t_envs	*tmp;
	t_envs	*last;
	int		i;

	i = 0;
	head = NULL;
	while (envs[i])
	{
		tmp = create_env_node(envs[i], d);
		if (head == NULL)
		{
			head = tmp;
			last = tmp;
		}
		else
		{
			last->next = tmp;
			last = tmp;
		}
		i++;
	}
	return (head);
}

void	init_data(t_data **d, char **envs)
{
	char	*cwd;

	*d = salloc(sizeof(t_data), NULL);
	(*d)->str_env = ft_str_array_dup(envs);
	(*d)->envs = parse_env(envs, *d);
	(*d)->sh_ln = NULL;
	(*d)->line = NULL;
	(*d)->exit_status = 0;
	(*d)->prompt = NULL;
	(*d)->non_printable_attempts = 0;
	if (!ft_getenv("PWD", *d))
	{
		cwd = getcwd(NULL, 0);
		if (cwd)
		{
			ft_setenv("PWD", cwd, *d);
			free(cwd);
		}
	}
	if (!ft_getenv("SHLVL", *d))
		ft_setenv("SHLVL", "1", *d);
}
