/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:14:59 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 23:01:38 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*continue_expand(char *expanded, char c)
{
	char	*ret;
	char	*temp;
	char	saved[2];

	saved[0] = c;
	saved[1] = '\0';
	temp = expanded;
	ret = ft_strjoin(expanded, saved);
	if (!ret)
		return (NULL);
	free(temp);
	return (ret);
}
