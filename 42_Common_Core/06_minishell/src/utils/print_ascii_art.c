/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii_art.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 19:50:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_ascii_art(const char *filename)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_printf("%s", buffer);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
}
