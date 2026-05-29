/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:41 by itjimene          #+#    #+#             */
/*   Updated: 2025/06/22 23:54:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*process_exit_status(t_data *d, char *expanded, int *ind)
{
	char	*env;
	char	*temp;

	env = ft_itoa(d->exit_status);
	if (!env)
	{
		free(expanded);
		return (NULL);
	}
	temp = expanded;
	expanded = ft_strjoin(expanded, env);
	free(temp);
	free(env);
	if (!expanded)
		return (NULL);
	(*ind)++;
	return (expanded);
}

static pid_t	get_current_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		exit(0);
	else if (pid > 0)
	{
		wait(NULL);
		return (pid - 1);
	}
	return (-1);
}

char	*process_pid_variable(char *exp, int *ind)
{
	pid_t	current_pid;
	char	*pid_str;
	char	*temp;

	current_pid = get_current_pid();
	pid_str = ft_itoa(current_pid);
	if (!pid_str)
	{
		free(exp);
		return (NULL);
	}
	temp = exp;
	exp = ft_strjoin(exp, pid_str);
	free(temp);
	free(pid_str);
	if (!exp)
		return (NULL);
	(*ind) += 2;
	return (exp);
}

char	*process_variable(t_data *d, char *s, char *exp, int *ind)
{
	char	*temp;
	char	*var;
	int		start;
	char	*env;

	start = *ind;
	while (s[*ind] && (ft_isalnum(s[*ind]) || s[*ind] == '_'))
		(*ind)++;
	var = ft_substr(s, start, *ind - start);
	if (!var)
	{
		free(exp);
		return (NULL);
	}
	env = ft_getenv(var, d);
	free(var);
	if (env)
	{
		temp = exp;
		exp = ft_strjoin(exp, env);
		free(temp);
		if (!exp)
			return (NULL);
	}
	return (exp);
}

char	*process_env_variable(t_data *d, char *exp, char *s, int *ind)
{
	char	*var;
	int		start;

	start = *ind;
	if (s[*ind] == '?')
		return (process_exit_status(d, exp, ind));
	if (s[*ind] == '$')
		return (process_pid_variable(exp, ind));
	if (ft_isdigit(s[*ind]))
	{
		(*ind)++;
		var = ft_substr(s, start, 1);
		if (!var)
		{
			free(exp);
			return (NULL);
		}
		free(var);
		return (exp);
	}
	return (process_variable(d, s, exp, ind));
}
