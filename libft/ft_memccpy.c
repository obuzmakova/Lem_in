/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:13:23 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/19 19:23:52 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)dst;
	p2 = (unsigned char*)src;
	while (n > 0)
	{
		if ((*p1++ = *p2++) != (unsigned char)c)
			n--;
		else
			return (p1);
	}
	return (NULL);
}
