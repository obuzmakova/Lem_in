#include "lemin.h"

void    ft_print(t_lemin *lemin) // добавить печать комманд и комментариев
{                                // поменять на наш принтф
    printf("%d\n", lemin->ant_num);
    ft_print_room(lemin);
    ft_print_links(lemin);
}

void    ft_print_room(t_lemin *lemin) // добавить печать координат
{
    t_room  *tmp;

    tmp = lemin->rooms;
    while ((tmp))
    {
        printf("%s ", tmp->name);
        printf("bfs_lvl %d\n", tmp->bfs_lvl); // проверка bfs, потом убрать
        tmp = tmp -> next;
    }
}

void    ft_print_links(t_lemin *lemin)
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