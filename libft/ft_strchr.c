/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:44:14 by mleticia          #+#    #+#             */
/*   Updated: 2019/12/12 18:37:08 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	p1;
	char	*p2;

	p1 = (char)c;
	p2 = (char*)s;
	while (*p2)
	{
		if (*p2 == p1)
			return ((char*)p2);
		p2++;
	}
	if (p1 == '\0')
		return ((char*)p2);
	return (0);
}
