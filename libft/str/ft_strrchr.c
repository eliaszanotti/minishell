/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:55:13 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/09 18:55:31 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	int				len;

	ch = c;
	len = 0;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == ch)
			return ((char *)(s + len));
		len--;
	}
	return (0);
}
