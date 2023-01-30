/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/01/30 14:34:13 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_remove_quote(char *str)
{
	char	*new_str;
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (str[++i])
		if (str[i] == '\'' || str[i] == '"')
			size++;
	if (size == 0)
		return (str);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != '\'' && *str != '"')
			new_str[i++] = *str;
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_parse_quotes(t_args *args)
{
	char	*current;
	int		i;
	int		j;

	i = -1;
	while (args->stack[++i])
	{
		j = -1;
		while (args->stack[i][++j])
		{
			current = args->stack[i][j];
			if (current[0] != '\'' && \
				current[ft_strlen(current)] != '\'')
				current = ft_replace_env(args, current);
			if (!current)
				return (ft_error(99));
			current = ft_remove_quote(current);
			args->stack[i][j] = current;
			if (!args->stack[i][j])
				return (ft_error(99));
		}
	}
	return (0);
}
