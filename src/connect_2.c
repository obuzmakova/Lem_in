/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:51:48 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 16:51:54 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		del_deadlock(t_lemin *lemin)
{
	int		check_del;
	t_link	*tmp;
	t_link	*del;

	check_del = 1;
	while (check_del)
	{
		check_del = 0;
		tmp = lemin->links;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			if ((del->start != lemin->start
				&& del->start->inp_lin == 0
				&& del->start->out_lin > 0)
				|| (del->end != lemin->end
				&& del->end->inp_lin > 0
				&& del->end->out_lin == 0))
			{
				del_link(lemin, del);
				check_del = 1;
			}
		}
	}
}

void		free_steps(t_step **steps)
{
	t_step	*tmp;

	if (steps)
	{
		while ((*steps))
		{
			tmp = (*steps);
			(*steps) = (*steps)->next;
			free(tmp);
		}
	}
}
