/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:45:25 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/16 18:51:53 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0) && (*s1 && *s2))
	{
		if (*s1 != *s2)
			return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
		s1++;
		s2++;
		n--;
	}
	if ((n > 0) && ((*s1 == '\0' && *s2) || (*s2 == '\0' && *s1)))
		return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
	return (0);
}
