#include "lemin.h"

t_tail  *create_el_tail(t_room *room)
{
    t_tail  *tmp;

    if (!(tmp = (t_tail *)ft_memalloc(sizeof(t_tail))))
        exit(1);
    tmp->room = room;
    tmp->next = NULL;
    return(tmp);
}

void    add_el_tail(t_tail **tail, t_tail *el)
{
    t_tail  *tmp;

	if (tail && *tail)
	{
		tmp = (*tail);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = el;
	}
	else if (tail)
		(*tail) = el;
}

t_tail  *head_tail(t_tail **tail)
{
    t_tail  *head;

    head = NULL;
    if (tail && *tail)
	{
		head = (*tail);
		(*tail) = (*tail)->next;
	}
	return (head);
}

void    add_neighb(t_lemin *lemin, t_tail **tail, t_room *room)
{
    t_link	*tmp;

	tmp = lemin->links;
	while (tmp)
	{
		if (tmp->start == room)
		{
			if (tmp->end->bfs_lvl == -1)
			{
				tmp->end->bfs_lvl = room->bfs_lvl + 1;
				add_el_tail(tail, create_el_tail(tmp->end));
			}
		}
		else if (tmp->end == room)
		{
			if (tmp->start->bfs_lvl == -1)
			{
				tmp->start->bfs_lvl = room->bfs_lvl + 1;
				add_el_tail(tail, create_el_tail(tmp->start));
			}
		}
		tmp = tmp->next;
	}
}

void    bfs(t_lemin *lemin)
{
    t_tail  *tail;
    t_tail  *head;

    tail = NULL;
    lemin->start->bfs_lvl = 0;
    add_el_tail(&tail, create_el_tail(lemin->start));
    while (tail != NULL)
    {
        head = head_tail(&tail);
        if (head->room != lemin->end)
        {
            add_neighb(lemin, &tail, head->room);
            lemin->max_bfs = head->room->bfs_lvl; // max bfs?
        }
        else
            lemin->end->bfs_lvl = 2147483647;
        free(head);
    }
}