/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:23:01 by mleticia          #+#    #+#             */
/*   Updated: 2019/12/12 18:37:08 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 && s2)
	{
		if (ft_strlen(s1) + ft_strlen(s2) + 1 == 0)
			return (0);
		result = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (result == 0)
			return (0);
		result = ft_strcat(result, (char*)s1);
		result = ft_strcat(result, s2);
		return ((char*)result);
	}
	return (0);
}
