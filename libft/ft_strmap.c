/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:09:44 by mleticia          #+#    #+#             */
/*   Updated: 2019/04/22 16:22:22 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*p1;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(p1 = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_memcpy(p1, s, ft_strlen(s));
	while (s[i])
	{
		p1[i] = f(s[i]);
		i++;
	}
	p1[i] = '\0';
	return (p1);
}
