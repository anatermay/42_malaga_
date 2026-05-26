/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 12:47:30 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export(t_data *d)
{
	char	**cmd;
	int		i;

	cmd = d->sh_ln->cmd;
	if (!cmd[1])
	{
		print_export_envs(d);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		export_variable(cmd[i], d);
		i++;
	}
}
