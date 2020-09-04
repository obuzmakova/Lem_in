/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:16:24 by mleticia          #+#    #+#             */
/*   Updated: 2019/09/27 20:20:34 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list **alst)
{
	t_list	*tmp;

	if (!(alst && *alst))
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstfreeone(&(*alst));
		*alst = tmp;
	}
	*alst = 0;
}
