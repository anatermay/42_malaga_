/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*array_free(char **array)
{
	int	index;

	if (!array)
		return (NULL);
	index = 0;
	while (array[index])
	{
		free(array[index]);
		array[index] = NULL;
		index++;
	}
	free(array);
	return (NULL);
}

void	free_envs(t_envs *envs)
{
	t_envs	*tmp;

	while (envs)
	{
		tmp = envs;
		envs = envs->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
}

void	free_redirects(t_redirect *redir)
{
	t_redirect	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		if (tmp->type)
			free(tmp->type);
		if (tmp->file)
			free(tmp->file);
		free(tmp);
		tmp = NULL;
	}
}

void	free_shell_line(t_shell_line *sh_ln)
{
	t_shell_line	*current;
	t_shell_line	*next;

	current = sh_ln;
	while (current)
	{
		next = current->next;
		if (current->line)
			free(current->line);
		if (current->cmd)
			array_free(current->cmd);
		if (current->redir)
			free_redirects(current->redir);
		free(current);
		current = next;
	}
}

void	free_data(t_data *d)
{
	if (!d)
		return ;
	if (d->sh_ln)
		free_shell_line(d->sh_ln);
	if (d->line)
		free(d->line);
	if (d->envs)
		free_envs(d->envs);
	if (d->str_env)
		ft_free_array(d->str_env);
	free(d);
}
