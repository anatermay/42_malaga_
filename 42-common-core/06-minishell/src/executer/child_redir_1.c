/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_redir_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:01:22 by aternero          #+#    #+#             */
/*   Updated: 2025/06/21 21:01:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	dup_and_close_output(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		ft_putstr_fd("minishell: dup2: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	close(fd);
	return (0);
}

int	handle_output_redirect(t_redirect *redir)
{
	int	fd;
	int	flags;

	if (ft_strcmp(redir->type, ">") == 0)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (ft_strcmp(redir->type, ">>") == 0)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		return (-1);
	fd = open(redir->file, flags, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(redir->file, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	return (dup_and_close_output(fd));
}

int	handle_input_file(t_redirect *redir)
{
	int	fd;

	fd = open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(redir->file, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		ft_putstr_fd("minishell: dup2: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	close(fd);
	return (0);
}

int	handle_input_redirect(t_redirect *redir, t_data *d)
{
	if (ft_strcmp(redir->type, "<") == 0)
		return (handle_input_file(redir));
	else if (ft_strcmp(redir->type, "<<") == 0)
		return (handle_heredoc(redir, d));
	return (0);
}

int	validate_input_files(t_shell_line *cmd_node)
{
	t_redirect	*redir;
	int			fd;

	redir = cmd_node->redir;
	while (redir)
	{
		if (ft_strcmp(redir->type, "<") == 0)
		{
			fd = open(redir->file, O_RDONLY);
			if (fd == -1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(redir->file, 2);
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(strerror(errno), 2);
				ft_putstr_fd("\n", 2);
				return (-1);
			}
			close(fd);
		}
		redir = redir->next;
	}
	return (0);
}
