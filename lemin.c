#include "lemin.h"

int main(void)
{
    t_lemin *lemin;

    lemin = ft_parser();
    bfs(lemin); // какая-то валидация на результаты bfs
    del_waste_links(lemin);
    get_direct(lemin);
    count_links(lemin);
    del_deadlock(lemin);
    del_waste_inp_lin(lemin);
    del_waste_out_lin(lemin);
    // распечатка карты, добавить структуры со всеми строками 

    ft_print(lemin);
    return (0);
}