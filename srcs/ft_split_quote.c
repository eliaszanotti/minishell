/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/01/03 16:52:41 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>

static size_t	ft_mallocsize(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (*s == '"')
			{
				s++;
				while (*s && *s != '"')
					s++;
			}
			else if (*s++ == '\'')
				while (*s && *s != '\'')
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

int	ft_get_i(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i++] == '"')
		{
			while (s[i] && s[i] != '"')
				i++;
			i++;
			break ;
		}
		else if (s[i - 1] == '\'')
		{
			while (s[i] && s[i] != '\'')
				i++;
			i++;
			break ;
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
		if ((s[0] == '"' && s[i - 1] == '"') \
				|| (s[0] == '\'' && s[i - 1] == '\''))
			tab[i_tab] = ft_substr(s, 1, i - 2);
		else
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

int	ft_check_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '"')
		{
			while (s[i] && s[i] != '"')
				i++;
			if (!s[i++])
				return (1);
		}
		else if (s[i - 1] == '\'')
		{
			while (s[i] && s[i] != '\'')
				i++;
			if (!s[i++])
				return (1);
		}
	}
	return (0);
}

int	ft_split_quote(t_args *args, char *s, char c)
{
	size_t	mallocsize;
	int		error_code;

	if (!s || !*s)
	{
		args->command_list = malloc(sizeof(char *));
		if (!args->command_list)
			return (0);
		args->command_list[0] = 0;
		return (0);
	}
	error_code = ft_check_quotes(s);
	if (error_code)
		return (error_code);
	while (*s == c)
		s++;
	mallocsize = ft_mallocsize(s, c);
	args->command_list = malloc(sizeof(char *) * (mallocsize + 1));
	if (!args->command_list)
		return (0);
	args->command_list = ft_splitstr(s, c, args->command_list, mallocsize);
	args->command_list[mallocsize] = NULL;
	return (0);
}
