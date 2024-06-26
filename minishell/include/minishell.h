/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:38:03 by jguerin           #+#    #+#             */
/*   Updated: 2024/05/08 17:39:39 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// --- [ include ] --- //

# include "../get_next_line/get_next_line.h"
# include "global_var.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// --- [ define bool ] --- //

# define TRUE 1
# define FALSE -1

// --- [ define FLAG ] --- //

# define HERE 2
# define PERM 3
# define DIRECTORY 4
# define IN 5
# define OUT 6

# define NO 10

// --- [ define Token ] --- //

# define UNKNOWN -1
# define REDIR_LEFT 1
# define REDIR_RIGHT 2
# define REDIR_D_RIGHT 3
# define REDIR_D_LEFT 4
# define FILE 5
# define HEREDOC_PASS 6

// --- [ define env ] --- //

# define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

// --- [ define error msg ] --- //

# define TOKEN_ERR "minishell: syntax error near unexpected token `"
# define TOKEN_ERR_SHORT "minishell: syntax error near unexpected token\n"
# define TOKEN_NL_ERR "minishell: syntax error near unexpected token `newline'\n"
# define AMBIG_ERR ": ambiguous redirect\n"
# define ID_ERR "minishell : invalid identifier\n"

// --- [ structure ] --- //

typedef struct Pipe
{
	int		n_steps;
}	t_pipe;

typedef struct xt
{
	int		i;
	int		j;
	int		k;
}	t_exit;

typedef struct shell
{
	int		mini;
	int		status;
	int		redir;
	int		argc;
	int		forked_cmd;
	char	*path;
	char	**heredoc;
	char	**all;
	char	**p_cmd;
	char	**n_c_cmd;
	char	**cmd;
	char	**env;
	t_pipe	pipl;
	t_exit	var;

}	t_shell;

// --- [ function ] --- //

/* tmp */

void		print_tab(char **tab);
void		tokenizer(char **test);

/* builtins */

void		env(char **env, char **cmd, t_shell *shell);

void		echo(char **args, t_shell *shell);

void		pwd(t_shell *shell);

void		ft_exit(char **argv, t_shell *shell, t_exit xt);

void		ft_cd(char **argv, t_shell *shell);

void		ft_export(char **cmd, char **argv, t_shell *shell);

void		ft_unset(char **cmd, char **argv, t_shell *shell);

/* launch */

void		launch(t_shell *shell);

/* parsing */

int			update(char c, int *in_q);
int			update_sd(char c, int *in_q, int *qs, int *qd);

int			parse(char *readed, int i, t_shell *shell);

void		change_nl(char *readed);
int			reboot_line(char *readed);

char		*quoted_line(char *line);
int			check_quote(char *s);

char		*rebuild_space_line(char *r, int j, int in_q);

char		**cut_cmd(char *line);

void		find_bull(t_shell *shell, char **cmd, int i);
int			isnt_bull(t_shell *shell, char **cmd);

char		*env_conversion(char *s, char **env, int i, t_shell *mini);

/* exec */

void		shell_execve(char **env, t_shell *shell);
void		execute_pipeline(t_shell *shell, int i, int j, int input_fd);

int			redir(t_shell *sh, int before);

void		heredoc(char *pass);
int			identifie(char *token, int before);

/* history */

void		make_history(t_shell *shell);
void		history(char *readed);

/* utils */

char		*actual_path(void);

int			quotes_cmd_size(char *line);
char		**make_cmds(char **av, int pipeline, int i, int j);

void		init_shell(t_shell *shell);

int			var_c(char *s, int i);
int			simp_char(char c, char *reject);
int			add_argc(char **argv);

/* utils redir */

void		st_cmd(t_shell *sh, int t1, int t2);
void		redir_right(char *file_name, int redir_type);
void		redir_left(char *file_name, char *pass, int redir_type);
int			redir_err(char **str);
int			id_n_co(t_shell *sh, int *bf, int i);

/* utils heredoc */

void		make_heredoc(char **f, int bf);
int			unexpected(int token, char **f);
void		heredoc_priority(int token, char **f);

/* utils free */

void		tab_free(char **tab);
void		global_free(t_shell *shell);
void		multfree(char *s1, char *s2, char **t1, char **t2);

/* utils print */

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_error(char *s1, char *s2, char *s3);
void		put_error(char *exe, char *file, int err, char *error);

/* utils copy */

char		*ft_strdup(char *s1);
char		**ft_tabdup(char **tab);

/* utils basic */

int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(char *str);
char		*ft_itoa(int nbr);
char		*ft_join(char *s1, char *s2);
char		*make_it_one(char **tab);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

/* utils env */

int			id_n_co(t_shell *sh, int *bf, int i);
int			check_env(char *s, char **env, int i);
int			ft_checkenv(char *str, char **env);
int			ft_checkenv2(char *str, char **env);
int			env_len(char **tab);
char		**add_env(char **env, char *var);
char		**give_path(char *str);
char		*ft_getenv(char *str, char **env);
void		sort_env(char **tab, int env_len);
void		incr_shlvl(t_shell *shell);

/* utils check */

int			command_exists(char *command, int i);
int			basic(int argc, char **env, t_shell *shell);
int			char_cmp(char *str, char *reject);
int			format_check(char *arg, t_shell *shell);
int			format_check_unset(char *arg, t_shell *shell);
int			nb_arg(char **arg);
int			is_flag_valid(char *str);
int			is_d(int n);
int			str_is_num(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			banned(char *readed);
void		is_neg(int n, t_shell *shell);

/* signal */

void		build_signal(void);

/* status */

void		set_status(int set, t_shell *shell);

/* bonus */

char		**wildcard(char **readed);

char		**get_dir(char *dir);
int			is_dir(char *dir);

int			first(char *str);
int			seconde(char *str);
int			third(char *str);

char		*first_type(char *line, char **dir, int type);

char		*seconde_type(char *line, char **dir);

char		*third_type(char *line, char **dir);

#endif
