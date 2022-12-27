/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:44:20 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/17 16:07:05 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_mallocsize(int n, size_t size)
{
	if (n < 0)
		return (ft_mallocsize(-n, size + 1));
	if (n >= 0 && n <= 9)
		return (size + 1);
	return (ft_mallocsize(n / 10, size + 1));
}

static char	*ft_charcat(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	s[i] = c;
	s[i + 1] = '\0';
	return (s);
}

static char	*ft_rev_int_tab(char *tab, int size)
{
	int		left_i;
	int		right_i;
	char	temp;

	left_i = 0;
	right_i = size - 1;
	while (left_i < right_i)
	{
		temp = tab[left_i];
		tab[left_i] = tab[right_i];
		tab[right_i] = temp;
		left_i++;
		right_i--;
	}
	return (tab);
}

static char	*ft_loop(char *str, int n)
{		
	while (n > 9)
	{
		ft_charcat(str, n % 10 + 48);
		n = n / 10;
	}
	if (n >= 0 && n <= 9)
		ft_charcat(str, n % 10 + 48);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;
	size_t	size_malloc;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size_malloc = ft_mallocsize(n, 0);
	str = ft_calloc((size_malloc + 1), sizeof(char));
	if (!str)
		return (0);
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	str = ft_loop(str, n);
	if (negative)
		ft_charcat(str, '-');
	str[size_malloc] = '\0';
	return (ft_rev_int_tab(str, size_malloc));
}
