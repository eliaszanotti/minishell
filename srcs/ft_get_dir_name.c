/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/10 18:26:50 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_dir_name(char *cwd)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	
	if (cwd != NULL)
	{
		i = ft_strlen(cwd);
		while (cwd[i] != '/')
			i--;
		if (!ft_strcmp(cwd , getenv("HOME")))
			cwd = ft_strjoin(" \e[34m⚡\e[46;97m ", "~");
		else
			cwd = ft_strjoin(" \e[34m⚡\e[46;97m ", cwd + i + 1);
		tmp = getenv("LOGNAME");
		tmp2 = ft_strjoin("\e[44m ", tmp);
		tmp = ft_strjoin(tmp2, cwd);
		free(tmp2);
		free(cwd);
		cwd = ft_strjoin(tmp, "\e[96m ➜ \e[0m ");
		free(tmp);
		return (cwd);
	}
	return (NULL);
}
