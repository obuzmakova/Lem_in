#include "lemin.h"

int main(void)
{
    t_lemin *lemin;

    lemin = ft_parser();
    bfs(lemin);
    ft_print(lemin);
    return (0);
}