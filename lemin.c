#include "lemin.h"

int ft_error(t_lemin *lemin, t_line *str)
{
    write(1, "ERROR\n", 6);
    if (lemin)
    {
        //
    }
    return (0);
}

int main(void)
{
    t_lemin *lemin;
    t_line  *str;

    if (!(str = (t_line*)ft_memalloc(sizeof(t_line))))
        exit(1);
    if (!(lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
        exit(1);
    if (!ft_parser(lemin, str))
        return (ft_error(lemin, str));
    bfs(lemin); // какая-то валидация на результаты bfs
    del_waste_links(lemin);
    get_direct(lemin);
    count_links(lemin);
    del_deadlock(lemin);
    del_waste_inp_lin(lemin);
    del_waste_out_lin(lemin);
    ways(lemin);
    ft_print(lemin, *str);
    launch_ant(lemin);
    return (0);
}