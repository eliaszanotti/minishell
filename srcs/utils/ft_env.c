/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:07:25 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 12:52:02 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_env(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*name;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	tmp = ft_substr(str, 0, i);
	j = i;
	while (str[j] && str[j] != ' ')
		j++;
	name = ft_substr(str, i + 1, j - i - 1);
	name = getenv(name);
	if (name)
		new_str = ft_strjoin(tmp, name);
	free(tmp);
	tmp = ft_strjoin(new_str, str + j);
	// new_str = ft_substr(new_str, 0, ft_strlen(new_str) - 1);//TODO ca sert a quoi batard?
	free(name);
	return (tmp);
}
