/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:54:18 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 16:57:06 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void free_all(char **str)
{
    int i;

    i = -1;
    if (str && str[0])
    {
        while (str[++i])
            ;
        while(--i >= 0)
        {
            free(str[i]);
            str[i] = NULL;
        }
        free(str);
        str = NULL;
    }
    else if (str)
    {
        free(str);
        str = NULL;
    }
}

void ft_error(t_lemin *lemin)
{
    write(1, "ERROR\n", 6);
    //ТУТ БУДУ ФРИШИТЬ
	free_lemin(&lemin); //ПРОВЕРЬ КАК ОНО ТУТ РАБОТАЕТ (Н)
    exit(1);
}

int main(void)
{
    t_lemin *lemin;
    //t_line  *str;

    //if (!(str = (t_line*)ft_memalloc(sizeof(t_line))))
    //    exit(1);
    if (!(lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
        exit(1);
    if (!ft_parser(lemin))
	    ft_error(lemin);
	bfs(lemin); // какая-то валидация на результаты bfs НЕ ДЕЛАЛА. ЧТО НАДО?
    del_waste_links(lemin);
    get_direct(lemin);
    count_links(lemin);
    del_deadlock(lemin);
    del_waste_inp_lin(lemin);
    del_waste_out_lin(lemin);
    ways(lemin);
    ft_print(lemin);
    launch_ant(lemin);
	free_lemin(&lemin);
    return (0);
}
