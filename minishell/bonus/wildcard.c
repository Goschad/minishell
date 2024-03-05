#include "../include/minishell.h"

static int is_dir_or_all(char *wild)
{
    int i;

    i = 0;
    if (ft_strlen(wild) == 1 && wild[0] == '*')
        return (2);
    if (wild[ft_strlen(wild)] == '*')
    {
        while (i < ft_strlen(wild) - 1)
        {
            if (wild[i] == '*')
                return (FALSE);
            i++;
        }
    }
    return (TRUE);
}

static char *launch_wildcard(char *wild, int choice)
{

}

char **wildcard(char **readed)
{
	int i;
	char **new;
	char **dir;

    i = 0;
	new = ft_tabdup(readed);
	dir = get_dir(".");
	if (dir == NULL)
		return (readed);
	while (new[i])
	{
		new[i] = launch_wildcard(new[i], /* function test all wildcard*/ 0);
		i++;
	}
	return (tab_free(dir), readed);
}