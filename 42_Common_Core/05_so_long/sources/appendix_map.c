/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendix_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:38:35 by aternero          #+#    #+#             */
/*   Updated: 2025/04/13 12:34:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/so_long.h"

int	fenced_map(char *str, int ok)
{
	if (ok != 1)
		ft_printf("Please, provide a valid map\n\tERROR: ");
	ft_printf(str);
	ft_printf("\n\t\t\t\t\t\t\t\t\t\t\t\t. . . ");
	if (ok == 1)
		ft_printf("OK");
	else
	{
		ft_printf("KO\n\t\t\t\t\t\t\t\t\t\t\t\t. . . STOP '>.<");
		ft_printf("\n\t\t\t\t\t\tYou can't play");
	}
	write(1, "\n", 1);
	if (ok == 1)
		return (TRUE);
	return (FALSE);
}

int	map_length(t_map *map)
{
	int	len;

	len = 0;
	while (map)
	{
		len++;
		map = map->next;
	}
	return (len);
}

int	strlen_double(char **str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	strlen_sl(char *str)
{
	int	length;

	length = 0;
	if (str[length] == '\0' || str[length] == '\n')
		return (0);
	while (str[length] == '1' || str[length] == '0' || str[length] == 'P'
		|| str[length] == 'C' || str[length] == 'E')
		length++;
	return (length);
}

void	map_error(char *str, int ok, int main)
{
	if (ok != 1 && main != 1)
		ft_printf("Please, provide a valid map\n\tERROR: ");
	ft_printf(str);
	ft_printf("\n\t\t\t\t\t\t\t\t\t\t\t\t. . . ");
	if (ok == 1)
		ft_printf("OK");
	else
	{
		ft_printf("KO\n\t\t\t\t\t\t\t\t\t\t\t\t. . . STOP '>.<");
		ft_printf("\n\t\t\t\t\t\tYou can't play");
	}
	write(1, "\n", 1);
}
