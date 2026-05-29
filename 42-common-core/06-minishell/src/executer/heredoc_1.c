/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:07:18 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 19:08:42 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*read_heredoc_input_while_1(char *line, char *content, t_data *d)
{
	char	*expanded_line;

	expanded_line = process_heredoc_line(line, d);
	if (!expanded_line)
	{
		if (content)
			free(content);
		restore_default_signals();
		return (NULL);
	}
	content = join_heredoc_lines(content, expanded_line);
	free(expanded_line);
	if (!content)
	{
		restore_default_signals();
		return (NULL);
	}
	return (content);
}

char	*read_heredoc_input_while_0(char *line, char *content, char *delimiter)
{
	char	*prompt;

	if (g_signal == S_CANCEL_EXEC)
	{
		if (content)
			free(content);
		restore_default_signals();
		return (NULL);
	}
	prompt = get_heredoc_prompt();
	if (!prompt)
	{
		if (content)
			free(content);
		restore_default_signals();
		return (NULL);
	}
	line = readline(prompt);
	free(prompt);
	if (!line)
	{
		handle_heredoc_eof(delimiter, content);
		return (NULL);
	}
	return (line);
}

char	*read_heredoc_input(char *delimiter, t_data *d)
{
	char	*content;
	char	*line;

	content = NULL;
	line = NULL;
	setup_heredoc_signals();
	while (1)
	{
		line = read_heredoc_input_while_0(line, content, delimiter);
		if (ft_strcmp(line, delimiter) == 0)
		{
			if (line)
				free(line);
			break ;
		}
		content = read_heredoc_input_while_1(line, content, d);
		if (!content)
			return (NULL);
	}
	restore_default_signals();
	return (content);
}

void	heredoc_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal = S_CANCEL_EXEC;
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	setup_heredoc_signals(void)
{
	g_signal = S_HEREDOC;
	signal(SIGINT, heredoc_signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
