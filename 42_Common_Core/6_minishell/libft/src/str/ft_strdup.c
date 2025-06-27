/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 23:12:05 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, ft_strlen((char *)s) + 1);
	return (new_str);
}
