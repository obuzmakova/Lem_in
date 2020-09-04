#include "lemin.h"

void    add_way(t_lemin *lemin, t_way *way)
{
	t_way	*prev;
	t_way	*tmp;

	prev = NULL;
	tmp = lemin->ways;
	if (tmp)
	{
		while (tmp && way->len > tmp->len)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (!prev)
			lemin->ways = way;
		else
			prev->next = way;
		way->next = tmp;
	}
	else
		lemin->ways = way;   
}

void    add_link(t_way *way, t_link *link)
{
	t_link	*prev;
	t_link	*tmp;

	prev = NULL;
	tmp = way->link;
	if (tmp)
	{
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		link->prev = prev;
		prev->next = link;
	}
	else
		way->link = link;
	way->len++;    
}

t_way	*create_way(void)
{
	t_way	*way;

	if (!(way = (t_way *)ft_memalloc(sizeof(t_way))))
	    exit(1);
	way->link = NULL;
	way->len = 0;
	way->next= NULL;
	return (way);
}

void	del_one_link(t_lemin *lemin, t_link *link)
{
	t_link	*prev;
	t_link	*tmp;

	prev = NULL;
	tmp = lemin->links;
	while (tmp && tmp != link)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev && tmp)
		lemin->links = tmp->next;
	else if (tmp)
		prev->next = tmp->next;
    link->next = NULL;
}

void    ways(t_lemin *lemin)
{
    t_way   *way;
    t_link  *link;

    while (lemin->links)
    {
        way = create_way();
        link = search_link(lemin, lemin->start, NULL);
        del_one_link(lemin, link);
        add_link(way, link);
        while (link->end != lemin->end)
        {
            link = search_link(lemin, link->end, NULL);
            del_one_link(lemin, link);
            add_link(way, link);
        }
        add_way(lemin, way);
    }
}