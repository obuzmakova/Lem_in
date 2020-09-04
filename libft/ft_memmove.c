/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:44:22 by mleticia          #+#    #+#             */
/*   Updated: 2019/09/27 19:03:30 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dstt;
	unsigned char *srct;

	dstt = (unsigned char*)dst;
	srct = (unsigned char*)src;
	if (len == 0 || dst == src)
		return (dst);
	if (src > dst)
	{
		while (len--)
			*dstt++ = *srct++;
	}
	else
		while (len--)
			*(dstt + len) = *(srct + len);
	return (dst);
}
