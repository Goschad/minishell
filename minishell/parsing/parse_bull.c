/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:43:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/21 15:43:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void find_bull(t_shell *shell, char **cmd)
{
    if (!ft_strcmp(cmd[0], "echo"))
        printf("echo\n");
    else if (!ft_strcmp(cmd[0], "env"))
        printf("env\n");
    else if (!ft_strcmp(cmd[0], "cd"))
        printf("cd\n");
    else if (!ft_strcmp(cmd[0], "pwd"))
        printf("pwd\n");
    else if (!ft_strcmp(cmd[0], "exit")) // faudra changer la valeur shell->mini
        printf("exit\n");
    else if (!ft_strcmp(cmd[0], "export"))
        printf("export\n");
    else if (!ft_strcmp(cmd[0], "unset"))
        printf("unset\n");
}

