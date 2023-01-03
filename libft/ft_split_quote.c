/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/01/03 12:32:15 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_mallocsize(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (*s++ == '"')
				while (*s && *s != '"')
					s++;
			while (*s && *s != c)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static char	**ft_freeall(char **tab, int max)
{
	while (max >= 0)
		free(tab[max--]);
	free(tab);
	return (0);
}

#include <stdio.h>

int ft_get_i(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i++] == '"')
		{
			while (s[i] && s[i] != '"')
				i++;
			i++;
			break;
		}
		else if (s[i - 1] == '\'')
		{
			while (s[i] && s[i] != '\'')
				i++;
			i++;
			break;
		}
	}
	return (i);
}

static char	**ft_splitstr(char const *s, char c, char **tab, size_t mallocsize)
{
	int		i;
	size_t	i_tab;

	i = 0;
	i_tab = 0;
	while (i_tab < mallocsize)
	{
		i = ft_get_i(s, c);
		tab[i_tab] = ft_substr(s, 0, i);
		if (!tab[i_tab])
			return (ft_freeall(tab, i_tab));
		s += i;
		while (*s == c && *s)
			s++;
		i_tab++;
		i = 0;
	}
	printf("\n\n\n");
	return (tab);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**tab;
	size_t	mallocsize;

	if (!s || !*s)
	{
		tab = malloc(sizeof(char *));
		if (!tab)
			return (0);
		tab[0] = 0;
		return (tab);
	}
	while (*s == c)
		s++;
	mallocsize = ft_mallocsize(s, c);
	tab = malloc(sizeof(char *) * (mallocsize + 1));
	if (!tab)
		return (0);
	tab = ft_splitstr(s, c, tab, mallocsize);
	tab[mallocsize] = NULL;
	return (tab);
}
