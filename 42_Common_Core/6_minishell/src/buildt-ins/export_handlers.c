/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_append_export(char *arg, char *plus_equal, t_data *d)
{
	char	*name;
	char	*value;

	*plus_equal = '\0';
	name = ft_strdup(arg);
	*plus_equal = '+';
	value = plus_equal + 2;
	if (name)
	{
		append_variable(name, value, d);
		free(name);
	}
}

static void	handle_regular_export(char *arg, char *equal_sign, t_data *d)
{
	char	*name;
	char	*value;

	*equal_sign = '\0';
	name = ft_strdup(arg);
	*equal_sign = '=';
	value = equal_sign + 1;
	if (name)
	{
		ft_setenv(name, value, d);
		free(name);
	}
}

static void	handle_no_value_export(char *arg, t_data *d)
{
	char	*name;

	name = ft_strdup(arg);
	if (name)
	{
		ft_setenv(name, NULL, d);
		free(name);
	}
}

void	export_variable(char *arg, t_data *d)
{
	char	*equal_sign;
	char	*plus_equal;
	int		is_append;

	if (!is_valid_identifier(arg))
		return (export_error(arg, d));
	plus_equal = ft_strnstr(arg, "+=", ft_strlen(arg));
	equal_sign = ft_strchr(arg, '=');
	is_append = (plus_equal != NULL && plus_equal < equal_sign);
	if (is_append)
		handle_append_export(arg, plus_equal, d);
	else if (equal_sign)
		handle_regular_export(arg, equal_sign, d);
	else
		handle_no_value_export(arg, d);
}
