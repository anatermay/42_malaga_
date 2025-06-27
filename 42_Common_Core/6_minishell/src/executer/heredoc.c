/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 21:12:45 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	restore_default_signals(void)
{
	g_signal = S_BASE;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

static char	*create_heredoc_tempfile(void)
{
	static int	heredoc_counter = 0;
	char		*number_str;
	char		*temp_path;

	number_str = ft_itoa(heredoc_counter++);
	if (!number_str)
		return (NULL);
	temp_path = ft_strjoin("/tmp/.minishell_heredoc_", number_str);
	free(number_str);
	return (temp_path);
}

int	process_heredoc(t_redirect *redir, t_data *d)
{
	char	*content;
	char	*temp_file;

	content = read_heredoc_input(redir->file, d);
	if (!content)
		return (-1);
	temp_file = create_heredoc_tempfile();
	if (!temp_file)
	{
		free(content);
		return (-1);
	}
	if (process_heredoc_2(redir, temp_file, content) == -1)
		return (-1);
	if (!redir->type)
	{
		unlink(temp_file);
		free(temp_file);
		return (-1);
	}
	return (0);
}

int	handle_heredoc(t_redirect *redir, t_data *d)
{
	int	fd;

	(void)d;
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
	unlink(redir->file);
	return (0);
}
