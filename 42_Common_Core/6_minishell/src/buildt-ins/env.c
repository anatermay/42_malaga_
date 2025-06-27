/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_data *d)
{
	t_envs			*tmp;
	t_shell_line	*current_cmd;

	if (d->pipeline.current_cmd)
		current_cmd = d->pipeline.current_cmd;
	else
		current_cmd = d->sh_ln;
	if (current_cmd->cmd[1])
	{
		ft_printf("env: %s: No such file or directory\n", current_cmd->cmd[1]);
		d->exit_status = 127;
		return ;
	}
	tmp = d->envs;
	while (tmp)
	{
		if (tmp->name != NULL && tmp->value != NULL && tmp->has_value)
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
