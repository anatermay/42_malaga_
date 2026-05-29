/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:02 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_cd_home(t_data *d)
{
	char	*path;

	path = ft_getenv("HOME", d);
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		d->exit_status = 1;
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		d->exit_status = 1;
	}
}

static void	handle_cd_previous(t_data *d)
{
	char	*path;

	path = ft_getenv("OLDPWD", d);
	if (!path)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		d->exit_status = 1;
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		d->exit_status = 1;
		return ;
	}
	ft_printf("%s\n", path);
}

static int	handle_cd_path(char *path, t_data *d)
{
	if (!path || !*path)
		return (1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		d->exit_status = 1;
		return (0);
	}
	return (1);
}

static void	process_cd_args(t_data *d)
{
	char	**cmd;

	cmd = d->sh_ln->cmd;
	if (!cmd[1])
	{
		handle_cd_home(d);
		if (d->exit_status != 0)
			return ;
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		handle_cd_previous(d);
		if (d->exit_status != 0)
			return ;
	}
	else if (!handle_cd_path(cmd[1], d))
		return ;
	update_pwd_vars(d);
}

void	cd(t_data *d)
{
	char	**cmd;

	cmd = d->sh_ln->cmd;
	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		d->exit_status = 1;
		return ;
	}
	process_cd_args(d);
}
