/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:13 by aternero          #+#    #+#             */
/*   Updated: 2025/02/26 18:47:45 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cub(char *buff)
{
	char	*newbuff;
	ssize_t	count[2];

	count[0] = 0;
	count[1] = 0;
	while (buff[count[0]] && buff[count[0]] != '\n')
		count[0]++;
	if (!buff[count[0]])
	{
		free(buff);
		return (NULL);
	}
	newbuff = malloc(sizeof(char) * (ft_strlen_gnl(buff) - count[0] + 1));
	if (!newbuff)
		return (NULL);
	count[0]++;
	count[1] = 0;
	while (buff[count[0]] != '\0')
		newbuff[count[1]++] = buff[count[0]++];
	newbuff[count[1]] = '\0';
	free(buff);
	return (newbuff);
}

static char	*ft_ctlc(char *buff)
{
	char	*newtl;
	ssize_t	index;

	index = 0;
	if (!buff[index])
		return (NULL);
	while (buff[index] && buff[index] != '\n')
		index++;
	newtl = (char *)malloc(sizeof(char) * (index + 2));
	if (!newtl)
		return (NULL);
	index = 0;
	while (buff[index] && buff[index] != '\n')
	{
		newtl[index] = buff[index];
		index++;
	}
	if (buff[index] == '\n')
	{
		newtl[index] = '\n';
		index++;
	}
	newtl[index] = '\0';
	return (newtl);
}

static char	*ft_sastl(int fd, char *buff)
{
	char	*newbuff;
	ssize_t	rb;

	newbuff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!newbuff)
		return (NULL);
	rb = 1;
	while (!ft_strchr_gnl(buff, '\n') && rb)
	{
		rb = read(fd, newbuff, BUFFER_SIZE);
		if (rb == -1)
		{
			free(newbuff);
			return (NULL);
		}
		newbuff[rb] = '\0';
		buff = ft_strjoin_gnl(buff, newbuff);
	}
	free(newbuff);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*newtl;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = ft_sastl(fd, buff);
	if (!buff)
		return (NULL);
	newtl = ft_ctlc(buff);
	buff = ft_cub(buff);
	return (newtl);
}
