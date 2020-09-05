#include "./include/lemin.h"

void    move_from_start(t_lemin *lemin, t_way *way)
{
    if (way->link->end == lemin->end)
    {
        lemin->ant_st--;
        lemin->ant_end++;
        add_step(lemin , create_step(++(lemin->ant_num), way->link->end));
    }
    else
    {
        lemin->ant_st--;
        way->link->end->ant_num = ++(lemin->ant_num);
        add_step(lemin , create_step(way->link->end->ant_num, way->link->end));
    }
}

int     calc(t_lemin *lemin, t_way *way)
{
    int     res;
    t_way   *tmp;

    res = 0;
    tmp = lemin->ways;
    while (tmp != way)
    {
        res = res + (way->len - tmp->len);
        tmp = tmp->next;
    }
    return (res);
}

void    ft_print_step(t_lemin *lemin)
{
    t_step  *tmp;

    tmp = lemin->steps;
    while (tmp)
    {
        write(1, "L", 1);
        ft_putnbr(tmp->ant_num);
        write(1, "-", 1);
        ft_putstr(tmp->room->name);
        write(1, " ", 1);
        tmp = tmp->next;
    }
    write(1, "\n", 1);
}