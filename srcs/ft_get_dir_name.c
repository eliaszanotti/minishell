/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/11 09:58:01 by tgiraudo         ###   ########.fr       */
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
		if (!ft_strcmp(cwd, getenv("HOME")))
			cwd = ft_strjoin(" \001\e[34m\002⚡\001\e[46;97m\002 ", "~");
		else
			cwd = ft_strjoin(" \001\e[34m\002⚡\001\e[46;97m\002 ", cwd + i + 1);
		tmp = getenv("LOGNAME");
		tmp2 = ft_strjoin("\001\e[44m ", tmp);
		tmp = ft_strjoin(tmp2, cwd);
		free(tmp2);
		free(cwd);
		cwd = ft_strjoin(tmp, "\001\e[96m\002 ➜ \001\e[0m ");
		free(tmp);
		return (cwd);
	}
	return (NULL);
}

// char	*ft_get_dir_name(char *cwd)
// {
// 	int		i;
// 	char	*tmp;

// 	if (cwd != NULL)
// 	{
// 		i = ft_strlen(cwd);
// 		while (cwd[i] != '/')
// 			i--;
// 		if (!ft_strcmp(cwd, getenv("HOME")))
// 			cwd = ft_strjoin(" ⚡ ", "~");
// 		else
// 			cwd = ft_strjoin(" ⚡ ", cwd + i + 1);
// 		tmp = getenv("LOGNAME");
// 		tmp = ft_strjoin(tmp, cwd);
// 		free(cwd);
// 		cwd = ft_strjoin(tmp, " ➜  ");
// 		free(tmp);
// 		return (cwd);
// 	}
// 	return (NULL);
// }
