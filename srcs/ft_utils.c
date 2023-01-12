/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:07 by elias             #+#    #+#             */
/*   Updated: 2023/01/12 12:34:49 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_delimiter(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "<") || !ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

// char	*ft_remove_quotes(char *str)
// {
// 	char	*tmp;

// 	if (str[0] == '"' || str[0] == '\'')
// 	{
// 		tmp = ft_substr(str, 1, ft_strlen(str) - 2);
// 		return (free(str), tmp);
// 	}
// 	return (str);
// }

void	*ft_exit(t_args *args)
{
	ft_free_args(args);
	exit(0);
}

void	ft_free_args(t_args *args)
{
	int	i;
	int	j;

	i = -1;
	while (args->stack[++i])
	{
		j = -1;
		while (args->stack[i][++j])
			free(args->stack[i][j]);
		free(args->stack[i]);
	}
	free(args->stack);
	i = -1;
}
