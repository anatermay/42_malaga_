/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_pwd_vars(t_data *d)
{
	char	*oldpwd;
	char	*newpwd;
	int		pwd_was_set;

	oldpwd = ft_getenv("PWD", d);
	pwd_was_set = (oldpwd != NULL);
	newpwd = getcwd(NULL, 0);
	if (!newpwd)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: ", 2);
		ft_putstr_fd("cannot access parent directories: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		d->exit_status = 1;
		return ;
	}
	if (pwd_was_set)
		ft_setenv("OLDPWD", oldpwd, d);
	else
		ft_unsetenv("OLDPWD", d);
	ft_setenv("PWD", newpwd, d);
	free(newpwd);
}
