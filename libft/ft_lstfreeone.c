/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:17:16 by mleticia          #+#    #+#             */
/*   Updated: 2019/09/27 20:20:34 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfreeone(t_list **alst)
{
	if (!(alst && *alst))
		return ;
	(*alst)->content_size = 0;
	free((*alst)->content);
	free(*alst);
	*alst = 0;
}
