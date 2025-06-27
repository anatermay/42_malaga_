/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:07:07 by aternero          #+#    #+#             */
/*   Updated: 2025/06/22 13:14:34 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	process_heredoc_2(t_redirect *redir, char *temp, char *content)
{
	if (write_content_to_file(content, temp) == -1)
	{
		free(content);
		free(temp);
		return (-1);
	}
	free(content);
	free(redir->file);
	redir->file = temp;
	free(redir->type);
	redir->type = ft_strdup("<");
	return (0);
}

char	*join_heredoc_lines(char *content, char *line)
{
	char	*temp;
	char	*result;

	if (!content)
		return (ft_strdup(line));
	temp = ft_strjoin(content, "\n");
	if (!temp)
	{
		free(content);
		return (NULL);
	}
	result = ft_strjoin(temp, line);
	free(temp);
	free(content);
	return (result);
}

char	*get_heredoc_prompt(void)
{
	if (isatty(STDIN_FILENO))
		return (ft_strdup("> "));
	else
		return (ft_strdup(""));
}

void	handle_heredoc_eof(char *delimiter, char *content)
{
	ft_putstr_fd("minishell: warning: here-document at line 1 ", 2);
	ft_putstr_fd("delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
	restore_default_signals();
	if (content)
		free(content);
}

char	*process_heredoc_line(char *line, t_data *d)
{
	char	*expanded_line;

	expanded_line = no_quotes_expand(line, d);
	free(line);
	return (expanded_line);
}
