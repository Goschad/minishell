/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:03 by mbouaza           #+#    #+#             */
/*   Updated: 2024/05/08 17:12:11 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*dest;

	i = -1;
	len = ft_strlen(s1);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (++i < len)
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**newtab;

	i = 0;
	newtab = NULL;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	newtab = malloc(sizeof(char *) * (i + 1));
	if (!newtab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		newtab[i] = ft_strdup(tab[i]);
		i++;
	}
	newtab[i] = NULL;
	return (newtab);
}
