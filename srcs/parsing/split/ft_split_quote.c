/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/14 13:47:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_split_quote(t_args *args, char *str)
{
	if (!str || !*str)
		return (1);
	if (ft_check_quotes(str))
		return (ft_error(20, NULL));
	args->command_list = NULL;
	while (*str)
	{
		str = ft_skip_redirect(&args->command_list, str);
		if (!str)
			return (ft_error(99, NULL));
		str = ft_skip_alpha(&args->command_list, str);
		if (!str)
			return (ft_error(99, NULL));
		str = ft_skip_expand(args, &args->command_list, str);
		if (!str)
			return (ft_error(99, NULL));
		str = ft_skip_pipe(&args->command_list, str);
		if (!str)
			return (ft_error(99, NULL));
		str = ft_skip_spaces(&args->command_list, str);
		if (!str)
			return (ft_error(99, NULL));
	}
	return (0);
}
