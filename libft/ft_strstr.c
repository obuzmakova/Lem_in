/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:09:04 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/22 15:00:21 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t s;
	size_t len;

	s = ft_strlen(needle);
	len = ft_strlen(haystack);
	if (!*needle)
		return ((char*)haystack);
	while (len > 0)
	{
		if (ft_strncmp(haystack, needle, s) != 0)
		{
			haystack++;
			len--;
		}
		else
			return ((char*)haystack);
	}
	return (NULL);
}
