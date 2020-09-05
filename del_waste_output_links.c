#include "./include/lemin.h"

void    del_second_out(t_lemin *lemin, t_link *link)
{
    t_room	*start;
	t_link	*tmp;
	t_link	*del;

	start = link->start;
	tmp = lemin->links;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		if (del->start == start && del != link)
			del_link(lemin, del);
	}
}

int     len_way(t_lemin *lemin, t_link *link, int len)
{
	if (link->end == lemin->end)
		return (len + 1);
	//if (link->end->inp_lin > 1) // не до конца понятно зачем 2 ифа ЭТО НЕ МОЙ КОММЕНТ?
	//	return (len + 1);
	return (len_way(lemin, search_link(lemin, link->end, NULL), len + 1));    
}

void    del_out(t_lemin *lemin, t_room *room)
{
    t_link  *tmp;
    t_link  *min_way;
    int     min_way_len;
    int     tmp_way_len;

    min_way_len = 2147483647;
    tmp_way_len = 0;
    tmp = lemin->links;
    while (tmp && room->out_lin > 1)
    {
        if (tmp->start == room)
        {
            tmp_way_len = len_way(lemin, tmp, 0);
            if (min_way_len > tmp_way_len)
            {
                min_way_len = tmp_way_len;
                min_way = tmp;
            }
        }
        tmp = tmp->next;
    }
    del_second_out(lemin, min_way);
    del_deadlock(lemin);
}

void    del_waste_out_lin(t_lemin *lemin)
{
    int     bfs;
    t_room  *tmp;

    bfs = lemin->max_bfs;
    while (bfs > 0)
    {
        tmp = lemin->rooms;
        while (tmp)
        {
            if (tmp->bfs_lvl == bfs && tmp->out_lin > 1)
                del_out(lemin, tmp);
            tmp = tmp->next;
        }
        bfs--;
    }
}