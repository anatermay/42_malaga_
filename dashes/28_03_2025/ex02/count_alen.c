/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:34:25 by aternero          #+#    #+#             */
/*   Updated: 2025/03/28 11:36:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_alen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == 'a')
			break ;
		count++;
	}
	return (count);
}
