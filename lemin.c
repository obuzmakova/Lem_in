#include "lemin.h"

int main(void)
{
    t_lemin *lemin;
    t_line  str;

    lemin = ft_parser(&str);
    bfs(lemin); // какая-то валидация на результаты bfs
    del_waste_links(lemin);
    get_direct(lemin);
    count_links(lemin);
    del_deadlock(lemin);
    del_waste_inp_lin(lemin);
    del_waste_out_lin(lemin);
    ways(lemin);
    ft_print(lemin, str);
    launch_ant(lemin);
    return (0);
}