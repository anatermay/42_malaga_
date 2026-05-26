/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:54:42 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/21 20:47:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*append_str(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static char	*parse_pwd(char *pwd, t_data *d)
{
	char	*home;
	char	*short_pwd;

	home = ft_getenv("HOME", d);
	if (home && pwd && ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		short_pwd = ft_strjoin("~", pwd + ft_strlen(home));
		if (!short_pwd)
			custom_exit(d, "Error: Memory allocation for PWD failed.",
				EXIT_FAILURE);
		return (short_pwd);
	}
	if (pwd)
		return (ft_strdup(pwd));
	return (ft_strdup(""));
}

static void	init_prompt_values(t_data *d, char **user, char **pwd)
{
	char	*pwd_path;

	*user = ft_getenv("USER", d);
	pwd_path = ft_getenv("PWD", d);
	if (!*user)
		*user = "user";
	*pwd = parse_pwd(pwd_path, d);
	if (!*pwd)
		custom_exit(d, "Error: Memory allocation for PWD failed.",
			EXIT_FAILURE);
}

static char	*build_prompt_simple(char *user, char *pwd)
{
	char	*prompt;

	prompt = ft_strdup("");
	if (!prompt)
		return (NULL);
	prompt = append_str(prompt, user);
	prompt = append_str(prompt, "@Shellder: ");
	prompt = append_str(prompt, pwd);
	prompt = append_str(prompt, "$> ");
	return (prompt);
}

char	*prompter(t_data *d)
{
	char	*prompt;
	char	*user;
	char	*pwd;

	init_prompt_values(d, &user, &pwd);
	prompt = build_prompt_simple(user, pwd);
	if (!prompt)
	{
		free(pwd);
		custom_exit(d, "Error: Memory allocation for prompt failed.",
			EXIT_FAILURE);
	}
	free(pwd);
	return (prompt);
}
