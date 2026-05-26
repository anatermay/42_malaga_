/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	extract_number(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((num * sign) & 0xFF);
}

void	handle_too_many_args(t_data *d)
{
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	d->exit_status = 1;
	if (d->pipeline.cmd_count > 1)
		exit(1);
}

void	handle_invalid_number(t_data *d, char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	if (d->pipeline.cmd_count > 1)
		exit(2);
	free_data(d);
	exit(2);
}

void	exit_with_code(t_data *d, int exit_code)
{
	if (d->pipeline.cmd_count > 1)
		exit(exit_code);
	free_data(d);
	exit(exit_code);
}
