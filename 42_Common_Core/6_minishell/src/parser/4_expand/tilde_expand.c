/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 20:21:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_tilde(char *str, t_data *d)
{
	char	*home;
	char	*expanded;

	if (!str || str[0] != '~')
		return (ft_strdup(str));
	home = ft_getenv("HOME", d);
	if (!home)
		return (ft_strdup(str));
	if (str[1] == '\0' || str[1] == '/')
	{
		if (str[1] == '\0')
			expanded = ft_strdup(home);
		else
			expanded = ft_strjoin(home, str + 1);
		if (!expanded)
			return (ft_strdup(str));
		return (expanded);
	}
	return (ft_strdup(str));
}
