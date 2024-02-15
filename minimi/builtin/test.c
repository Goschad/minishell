#include "../include/minishell.h"

int	lol(char **argv, t_shell *shell)
{
	int i = 1;
	int j = 0;
	char *path;

	if(shell->argc == 1)
		return (1);
	else if (shell->argc > 2)
	{
		ft_putstr_fd(argv[i], 2);
		ft_putstr_fd(": Too many arguments\n", 2);
		return (1);
	}
	else if (argv[i][j] == '~')
	{
		path = ft_getenv("HOME", shell->env);
		if (chdir(path) != 0)
			printf("No such file or directory\n");
	}
}
/*
static int	cd_home(char **env)
{
	t_shell *shell;
	char	*path;

	path = ft_getenv("HOME", shell->env);
	if (!path)
	{
		ft_putstr_fd("Home not found\n", 2);
		return (-1);
	}
	if (chdir(path))
	{
		ft_putstr_fd("cd: No such file or directory\n", 2);
		return (-1);
	}
	return (0);
}*/

int	ft_cd(t_shell *shell)
{
	int err;
	char *path;

	if (nb_arg(shell->argv + shell->offset) > 2)
	{
		printf("minishell: cd: too many arguments\n");
		return (-1);
	}
	if (shell->args[shell->offset + 1])
	{
		path = shell->argv[shell->offset + 1];
		err = chdir(path);
		if (err)
		{
			ft_putstr_fd("no such file or directory\n", 2);
			return (-1);
		}
		return (0);
	}
	return (cd_home(shell->env));
}

