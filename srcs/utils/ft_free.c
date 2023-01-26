/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:07:48 by elias             #+#    #+#             */
/*   Updated: 2023/01/26 14:47:34 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_freeall(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
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
