/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:30:06 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/16 15:36:49 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p1;

	p1 = (unsigned char*)s;
	while (n > 0)
	{
		if (*p1 != (unsigned char)c)
		{
			p1++;
			n--;
		}
		else
			return (p1);
	}
	return (NULL);
}
