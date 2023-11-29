/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:11:54 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/10 04:07:48 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void global_free(t_shell *shell)
{
	if (shell->parse->complete_cmd)
		free(shell->parse->complete_cmd);
	if (shell->parse->split_cmd)
		tab_free(shell->parse->split_cmd);
	if (shell->env)
		tab_free(shell->env);
	if (shell)
		free(shell);
}