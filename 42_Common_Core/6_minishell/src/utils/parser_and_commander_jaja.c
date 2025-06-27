/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_commander_jaja.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/24 10:49:06 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>

int	has_non_printable_chars(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (!(line[i] >= ' ' && line[i] <= '~')
			&& !((unsigned char)line[i] >= 160 && (unsigned char)line[i] <= 255)
			&& line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	handle_non_printable_input(t_data *d)
{
	d->non_printable_attempts++;
	ft_printf("\n⚠️  EXCUSE ME. I'm sorry, but if you want to blow ");
	ft_printf("up my shell\n");
	ft_printf("🔒 You'll have to wait 10 seconds \n");
	ft_printf("💡 This is to prevent attacks like ");
	ft_printf("'./minishell < /dev/urandom'\n\n");
	ft_printf("🚨 THREE STRIKES, YOU'RE OUT! 🚨\n");
	ft_printf("🔥 Too many non-printable character attempts. ");
	ft_printf("Terminating shell.\n");
	custom_exit(d, "Security violation: Max attempts reached",
		EXIT_FAILURE);
}

void	parser_and_commander_jaja(t_data *d)
{
	if (has_non_printable_chars(d->line))
		handle_non_printable_input(d);
}
