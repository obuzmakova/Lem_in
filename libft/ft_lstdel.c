/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:11:19 by mleticia          #+#    #+#             */
/*   Updated: 2019/09/27 19:47:26 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!(alst && *alst && del))
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = tmp;
	}
	*alst = 0;
}
