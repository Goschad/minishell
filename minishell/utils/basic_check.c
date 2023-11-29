/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:31:05 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/07 16:14:33 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// a supprimer

void print_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);
}

int basic(int argc, char **env, t_shell *shell)
{
	if (argc != 1)
		return (ft_putstr_fd("Argument error\n", 2), -1);
	init_shell(shell);
	shell->env = ft_tabdup(env);
	if (!shell->env)
		return (ft_putstr_fd("Env error\n", 2), -1);
	return (1);
}	