/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:47:56 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/09 21:24:46 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	end;
	size_t	len_s;

	if (s == 0)
		return (0);
	end = 0;
	len_s = ft_strlen(s);
	if (start < len_s)
		end = len_s - start;
	if (end > len)
		end = len;
	new_s = malloc(sizeof(char) * end + 1);
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s + start, end + 1);
	return (new_s);
}
