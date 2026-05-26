/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*salloc(size_t size, t_data *d)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		custom_exit(d, "Error: Memory allocation failed", EXIT_FAILURE);
	return (ptr);
}
