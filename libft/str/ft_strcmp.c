/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:37:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/27 18:40:02 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	while (*copy_s1 && *copy_s2 && *copy_s1 == *copy_s2)
	{
		copy_s1++;
		copy_s2++;
	}
	return (*copy_s1 - *copy_s2);
}
