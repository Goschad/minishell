/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/07 13:52:34 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
}

void multfree(char *s1, char *s2, char **t1, char **t2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (t1)
		tab_free(t1);
	if (t2)
		tab_free(t2);
}

void global_free(t_shell *shell)
{
	if (shell->env)
		tab_free(shell->env);
	if (shell->heredoc)
		free(shell->heredoc);
	if (shell->n_c_cmd)
		tab_free(shell->n_c_cmd);
	if (shell)
		free(shell);
}