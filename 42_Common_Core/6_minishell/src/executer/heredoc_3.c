/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:09:48 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 19:08:48 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	write_content_to_file(char *content, char *temp_file)
{
	int	fd;

	fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: heredoc: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	if (content && content[0])
	{
		write(fd, content, ft_strlen(content));
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}

char	*read_heredoc_input_aux( char *line, char *content, char *delimiter)
{
	line = read_heredoc_input_while_0(line, content, delimiter);
	if (!line)
	{
		if (content)
			free(content);
		restore_default_signals();
		return (NULL);
	}
	return (line);
}
