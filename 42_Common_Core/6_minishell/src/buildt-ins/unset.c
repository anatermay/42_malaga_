/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(t_data *d)
{
	int		i;
	char	**cmd;

	cmd = d->sh_ln->cmd;
	i = 1;
	while (cmd[i])
	{
		if (is_valid_identifier(cmd[i]) && ft_getenv(cmd[i], d))
			ft_unsetenv(cmd[i], d);
		i++;
	}
}
