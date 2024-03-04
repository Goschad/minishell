# ifndef MINISHELL_H
# define MINISHELL_H

// --- [ include ] --- //

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../get_next_line/get_next_line.h"
# include <string.h>

// --- [ define ] --- //

// --- [ structure ] --- //

struct Pipe
{
	int n_steps;
} typedef t_pipe;

struct shell
{
	int		mini;
	int		status;
	int		redir;
	int		argc;
	int 	forked_cmd;
	char	**all;
	char	**p_cmd;
	char	**cmd;
	char	**env;
	t_pipe  pipl;

} typedef t_shell;

struct xt
{
	int		i;
	int		j;
	int		k;
} typedef t_exit;


// --- [ function ] --- //

// tmp

void	print_tab(char **tab);

/* builtins */

void	env(char **env, char **cmd);

int		echo(char **args);

void	pwd(void);

void	ft_exit(char **argv, t_shell *shell, t_exit xt);

int		ft_cd(char **argv, t_shell *shell);

//int		ft_cd(char **argv, t_shell *shell);

/* launch */

void	launch(t_shell *shell);

/* parsing */

int		tokenizer(char *token);

int		update(char c, int *in_q);

void	parse(char *readed, t_shell *shell);

void	change_nl(char *readed);
char	*reboot_line(char *readed);

char	*wildcard(char *readed);

char	*quoted_line(char *line);
int		check_quote(char *s);

char	*rebuild_space_line(char *readed, int j, int in_q);

char	**cut_cmd(char *line);

void	find_bull(t_shell *shell, char **cmd, int i);
int		isnt_bull(t_shell *shell, char **cmd, int i);

/* exec */

void	shell_execve(char *e_cmd, char **env, t_shell *shell);
void	execute_pipeline(t_shell *shell, int i, int j, int input_fd);

void	redir(t_shell *shell, char **cmds);

/* history */

void	make_history(t_shell *shell);
void	history(char *readed);

/* utils */

char 	*actual_path(void);

int		quotes_cmd_size(char *line);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

char	**ft_split(char const *s, char c);

int		basic(int argc, char **env, t_shell *shell);
int		nb_arg(char **arg);
int		is_flag_valid(char *str);
int		is_d(int n);
int		str_is_num(char *str);
void	is_neg(int n, t_shell *shell);

void		init_shell(t_shell *shell);

char	*ft_strdup(char *s1);
char	**ft_tabdup(char **tab);

int		ft_strcmp(char *s1, char *s2);
char	*ft_join(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_atoi(char *str);

void	tab_free(char **tab);
void	global_free(t_shell *shell);

char	*ft_getenv(char *str, char **env);

void	set_status(int set, t_shell *shell);

#endif
