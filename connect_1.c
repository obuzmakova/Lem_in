#include "./include/lemin.h"

void    del_link(t_lemin *lemin, t_link *link)
{
    t_link  *prev;
    t_link  *tmp;

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
    if (link->start->out_lin > 0)
        link->start->out_lin--;
    if (link->end->inp_lin > 0)
        link->end->inp_lin--;
    free(link);
}

void    del_waste_links(t_lemin *lemin)
{
    t_link  *tmp;
    t_link  *del;

    tmp = lemin->links;
    while (tmp)
    {
        del = tmp;
        tmp = tmp->next;
        if (del->start->bfs_lvl == -1 || del->end->bfs_lvl == -1
        || del->start->bfs_lvl == del->end->bfs_lvl)
            del_link(lemin, del);
    }
}

void    swap_rooms(t_room **start, t_room **end)
{
    t_room  *tmp;

    tmp = *start;
    *start = *end;
    *end = tmp;
}

void    get_direct(t_lemin *lemin)
{
    t_link  *tmp;

    tmp = lemin->links;
    while (tmp)
    {
        if (tmp->start->bfs_lvl > tmp->end->bfs_lvl)
            swap_rooms(&tmp->start, &tmp->end);
        tmp = tmp->next;
    }
}

void    count_links(t_lemin *lemin)
{
    t_link  *tmp;

    tmp = lemin->links;
    while (tmp)
    {
        tmp->start->out_lin++;
        tmp->end->inp_lin++;
        tmp = tmp->next;
    }
}