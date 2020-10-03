/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:00:27 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 17:00:29 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_print_str(t_line *str)
{
	while (str->cont)
	{
		ft_putstr(str->cont);
		write(1, "\n", 1);
		str = str->next;
	}
	write(1, "\n", 1);
}

void		ft_print(t_lemin *lemin)
{
	ft_print_str(lemin->str);
}
