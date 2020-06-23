/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:06:28 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/26 15:48:43 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(unsigned int a, int c)
{
	if (a == 0)
		c++;
	while (a > 0)
	{
		a = a / 10;
		c++;
	}
	return (c);
}

static char			*ft_frstr(char *s1, unsigned int d, unsigned int g)
{
	while (g)
	{
		s1[g - 1] = d % 10 + '0';
		g--;
		d = d / 10;
	}
	return (s1);
}

char				*ft_itoa(int n)
{
	char			*p1;
	int				sign;
	unsigned int	i;
	unsigned int	num;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n = (unsigned int)(-n);
		i++;
	}
	i = (unsigned int)ft_size(n, i);
	if (!(p1 = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	p1[i] = '\0';
	num = n;
	p1 = ft_frstr(p1, num, i);
	if (sign == -1)
		p1[0] = '-';
	return (p1);
}
