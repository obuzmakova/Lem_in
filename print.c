#include "lemin.h"

void    ft_print_room(t_lemin *lemin) // добавить печать координат
{
    t_room  *tmp;

    tmp = lemin->rooms;
    while ((tmp))
    {
        printf("%s ", tmp->name);
        printf("bfs_lvl %d ", tmp->bfs_lvl); // проверка bfs, потом убрать
        printf("inp %d out %d\n", tmp->inp_lin, tmp->out_lin); // проверка, потом убрать
        tmp = tmp -> next;
    }
}

void    ft_print_links(t_lemin *lemin) // не печатает удаленные ссылки, создать копию ссылок для печати в самом начале 
{
    t_link  *tmp;

    tmp = lemin->links;
    while ((tmp))
    {
        printf("%s-%s\n", tmp->start->name, tmp->end->name);
        tmp = tmp->next;
    }
    printf("\n");
}

void    ft_print_ways(t_lemin *lemin) // не печатает удаленные ссылки, создать копию ссылок для печати в самом начале 
{
    t_way  *tmp;
    t_link *tmp2;

    tmp = lemin->ways;
    printf("ways\n");
    while ((tmp))
    {
        tmp2 = tmp->link;
        while(tmp2)
        {
            printf("%s", tmp2->start->name);
            tmp2 = tmp2->next;
        }
        printf("\n");
        tmp = tmp->next;
    }
    printf("\n");
}

void    ft_print_str(t_line str)
{
    while (str.cont)
    {
        printf("%s\n", str.cont);
        //if (str.next)
            str = *str.next;
        //else
        //    break;
    }
    printf("\n");
}

void    ft_print(t_lemin *lemin, t_line str) // добавить печать комманд и комментариев
{                                // поменять на наш принтф
    //printf("%d\n", lemin->ant_num);
    //ft_print_room(lemin);
   // ft_print_links(lemin);
    //ft_print_ways(lemin);
    ft_print_str(str);
}