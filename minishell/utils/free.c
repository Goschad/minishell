/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/26 10:30:20 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
}

void	global_free(t_shell *shell)
{
	if (shell->env)
		tab_free(shell->env);
	if (shell->heredoc)
		free(shell->heredoc);
	if (shell)
		free(shell);
}
