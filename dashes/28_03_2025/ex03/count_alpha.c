/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:36:30 by aternero          #+#    #+#             */
/*   Updated: 2025/03/28 12:23:10 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	count_alpha(char *str, int current)
{
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == str[current])
			count++;
		index++;
	}
	if (current != 0)
		printf(", ");
	printf("%d", count);
	printf("%c", str[current]);
}

void	check_alpha_in_str(char *argv, char alpha, int length)
{
	int	index;

	index = length;
	length--;
	while (length >= 0)
	{
		if (argv[length] == alpha)
			return ;
		length--;
	}
	count_alpha(argv, index);
}

char	*to_lower(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] + 32;
		index++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int		index;

	if (argc == 2)
	{
		argv[1] = to_lower(argv[1]);
		index = 0;
		while (argv[1][index])
		{
			check_alpha_in_str(argv[1], argv[1][index], index);
			index++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
