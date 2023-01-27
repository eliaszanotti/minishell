/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/27 21:11:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_prompt(t_args *args, char *cwd) // TODO segfault with env -i + leaks
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (cwd != NULL)
	{
		i = ft_strlen(cwd);
		while (cwd[i] != '/')
			i--;
		tmp = ft_getenv(args, "HOME");
		if (!ft_strcmp(cwd, tmp))
			cwd = ft_strjoin(" ⚡\001\e[46;90m\ue0b0\002 ", "~");
		else
			cwd = ft_strjoin(" ⚡\001\e[46;90m\ue0b0\002 ", cwd + i + 1);
		free(tmp);
		tmp = ft_getenv(args, "LOGNAME");
		tmp2 = ft_strjoin("\001\e[100;36m ", tmp);
		free(tmp);
		tmp = ft_strjoin(tmp2, cwd);
		free(tmp2);
		free(cwd);
		cwd = ft_strjoin(tmp, " \001\e[36;49m\ue0b0\e[0m\002 ");
		free(tmp);
		return (cwd);
	}
	return (NULL);
}
