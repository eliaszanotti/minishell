/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/01/24 14:34:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_mallocsize(char const *s, char c)
{
	size_t	count;
	char	quote;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (*s == '"' || *s == '\'')
			{
				quote = *s++;
				while (*s && *s != quote)
					s++;
			}
			while (*s && *s != c)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static int	ft_get_i(char const *s, char c)
{
	char	quote;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
		}
		i++;
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
			return (ft_freeall(tab));
		s += i;
		while (*s == c && *s)
			s++;
		i_tab++;
		i = 0;
	}
	return (tab);
}

static int	ft_check_quotes(char *s)
{
	char	quote;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (!s[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_split_quote(t_args *args, char *s, char c)
{
	size_t	mallocsize;

	if (!s || !*s)
	{
		args->command_list = malloc(sizeof(char *));
		if (!args->command_list)
			return (ft_error(99));
		args->command_list[0] = 0;
		return (0);
	}
	if (ft_check_quotes(s))
		return (ft_error(3));
	while (*s == c)
		s++;
	mallocsize = ft_mallocsize(s, c);
	args->command_list = malloc(sizeof(char *) * (mallocsize + 1));
	if (!args->command_list)
		return (ft_error(99));
	args->command_list = ft_splitstr(s, c, args->command_list, mallocsize);
	args->command_list[mallocsize] = NULL;
	return (0);
}
