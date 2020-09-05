#include "./include/lemin.h"

void    ft_print_ways(t_lemin *lemin) // не печатает удаленные ссылки, создать копию ссылок для печати в самом начале 
{
    t_way  *tmp;
    t_link *tmp2;

    tmp = lemin->ways;
    ft_putstr("ways");
    write(1, "\n", 1);
    while ((tmp))
    {
        tmp2 = tmp->link;
        while(tmp2)
        {
            ft_putstr(tmp2->start->name);
            tmp2 = tmp2->next;
        }
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    write(1, "\n", 1);
}

void    ft_print_str(t_line str)
{
    while (str.cont)
    {
        ft_putstr(str.cont);
        write(1, "\n", 1);
        //if (str.next)
            str = *str.next;
        //else
        //    break;
    }
    write(1, "\n", 1);
}

void    ft_print(t_lemin *lemin, t_line str) // добавить печать комманд и комментариев
{                                // поменять на наш принтф
    //printf("%d\n", lemin->ant_num);
    //ft_print_room(lemin);
   // ft_print_links(lemin);
    //ft_print_ways(lemin); //ТУТ МОЖНО ПО ПРИКОЛУ ПОСМОТРЕТЬ ПУТИ КОТОРЫЕ СОЗДАЛИСЬ
    ft_print_str(str);
}