/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exec_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:56:50 by aternero          #+#    #+#             */
/*   Updated: 2025/06/21 20:57:04 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*check_absolute_path(const char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

static char	*search_in_paths(const char *cmd, char **paths)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return ((char *)array_free(paths));
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return ((char *)array_free(paths));
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

char	*find_cmd_path_in_exec(const char *cmd, t_data *d)
{
	char	*path_var;
	char	**paths;
	char	*result;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	result = check_absolute_path(cmd);
	if (result)
		return (result);
	path_var = ft_getenv("PATH", d);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	result = search_in_paths(cmd, paths);
	array_free(paths);
	return (result);
}
