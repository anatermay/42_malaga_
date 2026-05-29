/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_identifier(char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i] && name[i] != '=' && name[i] != '+')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	print_export_envs(t_data *d)
{
	t_envs	*tmp;

	sort_envs(d);
	tmp = d->envs;
	while (tmp)
	{
		if (tmp->name)
		{
			ft_printf("declare -x %s", tmp->name);
			if (tmp->has_value)
				ft_printf("=\"%s\"", tmp->value);
			ft_printf("\n");
		}
		tmp = tmp->next;
	}
}

void	export_error(char *arg, t_data *d)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	d->exit_status = 1;
}

void	append_variable(char *name, char *value, t_data *d)
{
	char	*old_value;
	char	*new_value;

	old_value = ft_getenv(name, d);
	if (old_value)
	{
		new_value = ft_strjoin(old_value, value);
		ft_setenv(name, new_value, d);
		free(new_value);
	}
	else
		ft_setenv(name, value, d);
}
