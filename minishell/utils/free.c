/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/25 14:07:55 by mbouaza          ###   ########.fr       */
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

void global_free(t_shell *shell)
{
	if (shell->env)
		tab_free(shell->env);
	if (shell->heredoc)
		free(shell->heredoc);
	if (shell)
		free(shell);
}