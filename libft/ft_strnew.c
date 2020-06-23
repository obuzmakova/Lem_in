/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:48:44 by mleticia          #+#    #+#             */
/*   Updated: 2019/12/12 18:37:08 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (size + 1 == 0)
		return (0);
	str = ft_memalloc(size + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return ((char*)str);
}
