/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:49:14 by aternero          #+#    #+#             */
/*   Updated: 2025/06/23 19:28:30 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Macros for signals lint */
# define _POSIX_C_SOURCE 200809L
# define _GNU_SOURCE

# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"

extern int	g_signal;

typedef enum e_signal
{
	S_BASE,
	S_HEREDOC,
	S_HEREDOC_END,
	S_SIGINT,
	S_SIGINT_CMD,
	S_CMD,
	S_CANCEL_EXEC,
	S_SIZE
}			t_signal;

typedef struct s_temp
{
	char			*sub;
	char			*expanded;
	int				quote;
	struct s_temp	*next;
}					t_temp;

typedef struct t_redirect
{
	char				*type;
	char				*file;
	struct t_redirect	*next;
}						t_redirect;

typedef struct s_temp_redir
{
	char			*line;
	char			*without_redir;
	t_redirect		*redir;
}					t_temp_redir;
typedef struct s_shell_line
{
	char				*line;
	char				**cmd;
	t_redirect			*redir;
	int					empty_quoted_var;
	struct s_shell_line	*next;
}						t_shell_line;

typedef struct s_envs
{
	char				*name;
	char				*value;
	int					has_value;
	struct s_envs		*next;
}						t_envs;

typedef struct s_pipeline
{
	int					pipefd[2];
	int					prev_pipe_read_end;
	int					current_pipe_write_end;
	int					is_last;
	pid_t				*pids;
	int					cmd_count;
	int					cmd_index;
	t_shell_line		*current_cmd;
}						t_pipeline;

typedef struct s_data
{
	char				*line;
	struct s_shell_line	*sh_ln;
	char				**str_env;
	struct s_envs		*envs;
	int					exit_status;
	char				*prompt;
	int					non_printable_attempts;
	t_pipeline			pipeline;
}						t_data;

	//	**	MAIN	**
void			loop(t_data *d);
void			loop_while(t_data *d);

	/*	UTILS	*/
int				process_input(t_data *d);
void			handle_signal_sigint_cmd(t_data *d);
void			handle_signal_sigint(t_data *d);

	//	**	BUILT-INS	**
	/*	CD	*/
void			cd(t_data *d);
void			update_pwd_vars(t_data *d);
	/*	ECHO	*/
void			echo(char **cmd);
	/*	ENV	*/
void			env(t_data *d);
	/*	EXIT	*/
void			exit_shell(t_data *d);
void			exit_with_code(t_data *d, int exit_code);
void			handle_invalid_number(t_data *d, char *arg);
void			handle_too_many_args(t_data *d);
int				extract_number(char *str);
int				is_valid_number(char *str);
	/*	EXPORT	*/
void			export(t_data *d);
void			export_variable(char *arg, t_data *d);
void			append_variable(char *name, char *value, t_data *d);
void			export_error(char *arg, t_data *d);
void			print_export_envs(t_data *d);
int				is_valid_identifier(char *name);
	/*	PWD	*/
void			pwd(void);
	/*	UNSET	*/
void			unset(t_data *d);

	//	**	EXECUTER	**
	/*	BUILTINS HANDLER	*/
int				execute_builtin(t_data *d);
int				is_builtin(const char *cmd);
int				execute_builtin_with_cmd(t_shell_line *cmd_node, t_data *d);
	/*	CHILD EXEC HANDLERS	*/
void			execute_external_command(t_shell_line *cmd_node, t_data *d);
	/*	CHILD EXEC	*/
void			execute_child_command(t_shell_line *cmd_node, t_data *d);
void			setup_child_signals(void);
void			handle_dollar_command(t_shell_line *cmd_node);
void			handle_empty_command(t_shell_line *cmd_node);
int				handle_file_execution(char *cmd_path, char **args);
char			*find_cmd_path_in_exec(const char *cmd, t_data *d);
	/*	CHILD REDIR	*/
int				apply_redirections(t_shell_line *cmd_node, t_data *d);
void			setup_stdin_redirection(t_data *d);
void			setup_stdout_redirection(t_data *d);
void			setup_child_redirections(t_data *d);
int				validate_input_files(t_shell_line *cmd_node);
int				handle_input_redirect(t_redirect *redir, t_data *d);
int				handle_input_file(t_redirect *redir);
int				handle_output_redirect(t_redirect *redir);
int				dup_and_close_output(int fd);
	/*	EXECUTER	*/
void			executer(t_data *d);
	/*	HANDLE PARENT BUILTINS	*/
int				handle_single_parent_buildin(t_data *d);
	/*	HEREDOC	*/
void			restore_default_signals(void);
int				process_heredoc(t_redirect *redir, t_data *d);
int				handle_heredoc(t_redirect *redir, t_data *d);
void			setup_heredoc_signals(void);
void			heredoc_signal_handler(int sig);
char			*read_heredoc_input(char *delimiter, t_data *d);
char			*process_heredoc_line(char *line, t_data *d);
void			handle_heredoc_eof(char *delimiter, char *content);
int				process_heredoc_2(t_redirect *redir, char *temp, char *content);
char			*join_heredoc_lines(char *content, char *line);
char			*get_heredoc_prompt(void);
int				write_content_to_file(char *content, char *temp_file);
char			*read_heredoc_input_aux( char *line, char *content,
					char *delimiter);
char			*read_heredoc_input_while_0(char *line, char *content,
					char *delimiter);
	/*	PARENT PIPES	*/
void			handle_parent_pipes(t_data *d);
	/*	PIPELINE	*/
int				execute_pipeline(t_data *d);
void			execute_pipeline_2(pid_t pid, t_data *d);
void			create_pipe_if_needed(t_data *d);
pid_t			fork_process(t_data *d);
int				validate_redirections(t_shell_line *cmd_node);
	/*	WAIT CHILDREN	*/
void			wait_for_children(t_data *d);

	//	**	PARSER	**
	/*	PARSER AND EXPANDER	*/
int				pre_process(t_data *d);
int				check_pipe_syntax(t_data *d, int index);
int				process_char_in_loop(t_data *d, int index, int quote,
					int first_non_space);
int				handle_ampersand_error(t_data *d, int index,
					int first_non_space);
void			print_ampersand_error(t_data *d, int index);
int				skip_quotes(char *line, int *index);
int				process_special_char(t_data *d, int *index);
int				check_redirect_syntax(t_data *d, int *index);
int				check_pipes_and_redirects(t_data *d);
	/*	INIT SHELL_LINE_T (COMMAND)	*/
t_shell_line	*command_struct(char *line, t_data *d);
t_shell_line	*command_node(t_temp_redir *redir, t_data *d);
t_shell_line	*init_command(t_temp_redir *redir);
int				prepare_cmd_array(t_shell_line *command, t_temp_redir *redir,
					char ***temp);
int				process_cmd_args(t_shell_line *command, char **temp,
					t_data *d);
int				handle_special_var(t_shell_line *command, int yndex);
void			cleanup_resources(t_temp_redir *redir, t_shell_line *command,
					char **temp, int free_cmd);
	/*	REDIRECT	*/
t_temp_redir	*redirect(char *str);
char			*init_without_redir(char *str);
t_redirect		*init_redirect(char **lines);
t_redirect		*new_redir_node(char **lines, char *line, int yndex);
char			*remove_redir_quotation(char *file);
int				redir_length(char *str);
int				is_redirect(char c);
int				there_is_redir(char *str);
int				skip_quotes(char *line, int *index);
void			print_ampersand_error(t_data *d, int index);
int				handle_ampersand_error(t_data *d, int index,
					int first_non_space);
int				process_char_in_loop(t_data *d, int index, int quote,
					int first_non_space);
int				check_pipe_syntax(t_data *d, int index);

	/*	PARSING	*/
char			*parsing(char *str, t_data *d);
char			*parsing_continue(char *str, t_data *d);
char			*remove_quotes(char *str);
char			*to_expand_and_join(t_temp *temp, t_data *d);
	/*	EXPAND	*/
char			*expand_tilde(char *str, t_data *d);
char			*no_quotes_expand(char *str, t_data *d);
char			*process_env_variable(t_data *d, char *exp, char *s, int *ind);
char			*process_variable(t_data *d, char *s, char *exp, int *ind);
char			*process_pid_variable(char *exp, int *ind);
char			*process_exit_status(t_data *d, char *expanded, int *ind);
char			*continue_expand(char *expanded, char c);
	/*	UTILS	*/
int				is_there_quotes(char *str);
int				is_there_dollars(char *str);
int				no_space_finder(char *str);
int				is_space(char c);
int				is_c(char c);
t_temp			*temp_list(char **array);
void			free_list(t_temp *temp);
t_temp			*add_first_node(char **array, int index);
t_temp			*add_next_node(t_temp *temp, char **array, int index);
t_temp			*temp_node_1(char *str);
char			*ft_strndup(const char *str, int init);
int				flag_calculator(char *line, int index, int quote);
		//	SPLIT	//
char			**quote_parsing_split(const char *str);
char			**parsing_split(const char *s, char c);
char			**redir_split(const char *str);
char			**redir_splited(const char *str, char **ret, int *final_count);
int				redir_words_counter(const char *str);
int				process_redirect_token(char **ret, char *str, int *index,
					int start);
int				process_file_token(char **ret, char *str, int *index);
int				handle_redirect_in_quote(char *str, int *index);
int				handle_other_char(char *str, int *index);
void			redir_splited_4(char *str, int *index);
int				parsing_count_words(char const *s, char c);

	//	**	UTILS	**
	/*	CUSTOM EXIT	*/
void			custom_exit(t_data *d, char *msg, int exit_code);
	/*	ENVS	*/
void			sort_envs(t_data *d);
void			ft_unsetenv(char *name, t_data *d);
int				ft_env_exists(char *name, t_data *d);
char			*ft_getenv(char *name, t_data *d);
void			ft_setenv(char *name, char *value, t_data *d);
	/*	ERROR UTILS	*/
void			print_minishell_error(char *cmd, char *error_msg);
void			print_command_not_found(char *cmd);
void			print_no_such_file(char *cmd);
void			print_is_directory(char *cmd);
void			print_permission_denied(char *cmd);
void			print_exec_error(char *cmd, char *error);
	/*	FREES	*/
void			*array_free(char **array);
void			free_envs(t_envs *envs);
void			free_redirects(t_redirect *redir);
void			free_shell_line(t_shell_line *sh_ln);
void			free_data(t_data *d);
	/*	STR ARRAY DUP	*/
char			**ft_str_array_dup(char **array);
	/*	INIT	*/
void			init_data(t_data **d, char **envs);
	/*	PARSER AND COMMANDER	*/
int				has_non_printable_chars(char *line);
void			handle_non_printable_input(t_data *d);
void			parser_and_commander_jaja(t_data *d);
	/*	PRINT ASCII ART	*/
void			print_ascii_art(const char *filename);
	/*	PROMPT COLOR	*/
char			*build_prompt_colors(char *user, char *pwd);
	/*	PROMPTER	*/
char			*append_str(char *s1, char *s2);
char			*prompter(t_data *d);
	/*	SALLOC	*/
void			*salloc(size_t size, t_data *d);
	/*	SIGNALS	*/
void			init_signals(void);
void			signal_handler(int sig);

#endif
