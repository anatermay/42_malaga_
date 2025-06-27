/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 19:50:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*build_prompt_colors(char *user, char *pwd)
{
	char	*prompt;

	prompt = ft_strdup("");
	if (!prompt)
		return (NULL);
	prompt = append_str(prompt, "\001\033[35m\002");
	prompt = append_str(prompt, user);
	prompt = append_str(prompt, "\001\033[34m\002@\001\033[33m\002");
	prompt = append_str(prompt, "Shellder");
	prompt = append_str(prompt, "\001\033[37m\002: \001\033[1;32m\002");
	prompt = append_str(prompt, pwd);
	prompt = append_str(prompt, "\001\033[0m\002$> ");
	return (prompt);
}
