/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ant_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:53:48 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 16:53:51 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lemin.h"

t_step  *create_step(int ant_num, t_room *room)
{
    t_step  *step;

    if (!(step = (t_step *)ft_memalloc(sizeof(t_step))))
        exit(1);
    step->ant_num = ant_num;
    step->room = room;
    step->next = NULL;
    return (step);
}

void    add_step(t_lemin *lemin, t_step *step) // ???
{
	t_step	*prev;
	t_step	*tmp;

	prev = NULL;
	tmp = lemin->steps;
	if (tmp)
	{
		while (tmp && step->ant_num> tmp->ant_num)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (!prev)
			lemin->steps = step;
		else
			prev->next = step;
		step->next = tmp;
	}
	else
		lemin->steps = step;
}

void    move_in_way(t_lemin *lemin, t_way *way)
{
    t_link  *tmp;

    tmp = way->link;
    while (tmp->next)
        tmp = tmp->next;
    while (tmp)
    {
        if (tmp->start->ant_num != -1 && tmp->end == lemin->end)
        {
            add_step(lemin , create_step(tmp->start->ant_num, tmp->end));
            tmp->start->ant_num = -1;
            lemin->ant_end++;
        }
        else if (tmp->start->ant_num != -1)
        {
            add_step(lemin , create_step(tmp->start->ant_num, tmp->end));
            tmp->end->ant_num = tmp->start->ant_num;
            tmp->start->ant_num = -1;
        }
        tmp = tmp->prev;
    }
}

void    launch_ant(t_lemin  *lemin)
{
    t_way   *tmp1;
    t_way   *tmp2;

    while (lemin->ant_st || lemin->ant_num != lemin->ant_end)
    {
        tmp1 = lemin->ways;
        while (tmp1)
        {
            move_in_way(lemin, tmp1);
            tmp1 = tmp1->next; 
        }
        tmp2 = lemin->ways;
        while (tmp2 && lemin->ant_st)
        {
            if (lemin->ant_st > calc(lemin, tmp2))
                move_from_start(lemin, tmp2);            
            tmp2 = tmp2->next; 
        }
        ft_print_step(lemin);
        // зафришить step
        lemin->steps = NULL;
    }
}
