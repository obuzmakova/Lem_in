/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:09:27 by mleticia          #+#    #+#             */
/*   Updated: 2019/09/27 20:33:04 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s;

	if (haystack == needle || *needle == '\0' || !(s = ft_strlen(needle)))
		return ((char*)(haystack));
	while (*haystack && len-- >= s)
	{
		if ((*haystack == *needle) && ft_strncmp(haystack, needle, s) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
