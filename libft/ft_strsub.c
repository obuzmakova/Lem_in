/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:07:23 by mleticia          #+#    #+#             */
/*   Updated: 2019/12/12 18:37:08 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (len == 0 && !s)
		return (0);
	if (s && *s && start < ft_strlen(s))
	{
		if (len + 1 == 0)
			return (0);
		result = ft_memalloc(len + 1);
		if (result == 0)
			return (0);
		result = ft_strncpy(result, (char*)s + start, len);
		return ((char*)result);
	}
	return (0);
}
