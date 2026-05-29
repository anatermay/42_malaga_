/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/23 16:38:11 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_shell(t_data *d)
{
	int	exit_code;

	if (d->pipeline.cmd_count == 1)
		ft_printf("exit\n");
	if (d->sh_ln->cmd[1])
	{
		if (d->sh_ln->cmd[2])
		{
			handle_too_many_args(d);
			return ;
		}
		if (!is_valid_number(d->sh_ln->cmd[1]))
		{
			handle_invalid_number(d, d->sh_ln->cmd[1]);
			return ;
		}
		exit_code = extract_number(d->sh_ln->cmd[1]);
		exit_with_code(d, exit_code);
	}
	exit_with_code(d, d->exit_status);
}
