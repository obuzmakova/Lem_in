/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_waste_input_links.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:52:38 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 16:52:41 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		del_second_inp(t_lemin *lemin, t_link *link)
{
	t_link	*tmp;
	t_link	*del;
	t_room	*end;

	end = link->end;
	tmp = lemin->links;
	end = link->end;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		if (del->end == end && del != link)
			del_link(lemin, del);
	}
}

t_link		*search_link(t_lemin *lemin, t_room *start, t_room *end)
{
	t_link	*tmp;

	tmp = lemin->links;
	while (tmp)
	{
		if (start && tmp->start == start)
			return (tmp);
		if (end && tmp->end == end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			find_div_way(t_lemin *lemin, t_link *link)
{
	if (link->start == lemin->start)
		return (0);
	if (link->start->out_lin > 1)
		return (1);
	return (find_div_way(lemin, search_link(lemin, NULL, link->start)));
}

void		del_inp(t_lemin *lemin, t_room *room)
{
	t_link	*tmp;
	t_link	*del;

	tmp = lemin->links;
	while (tmp && room->inp_lin > 1)
	{
		del = tmp;
		tmp = tmp->next;
		if (del->end == room)
		{
			if (!find_div_way(lemin, del))
				del_second_inp(lemin, del);
			else
				del_link(lemin, del);
			del_deadlock(lemin);
		}
	}
}

void		del_waste_inp_lin(t_lemin *lemin)
{
	int		bfs;
	t_room	*tmp;

	bfs = 1;
	while (bfs <= lemin->max_bfs)
	{
		tmp = lemin->rooms;
		while (tmp)
		{
			if (tmp->bfs_lvl == bfs
			&& tmp->inp_lin > 1)
				del_inp(lemin, tmp);
			tmp = tmp->next;
		}
		bfs++;
	}
}
