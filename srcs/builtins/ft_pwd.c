/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:17:03 by elias             #+#    #+#             */
/*   Updated: 2023/01/30 14:03:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_args *args)
{
	char	*env;
	
	env = ft_getenv(args, "PWD");
	if (env)
		printf("%s\n", env);
	return (free(env), 0);
}
