/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:05:22 by mleticia          #+#    #+#             */
/*   Updated: 2019/09/27 21:08:06 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *alst)
{
	size_t count;

	count = 0;
	while (alst)
	{
		alst = alst->next;
		count++;
	}
	return (count);
}
