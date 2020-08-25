#include "lemin.h"

int     ft_type(char *line)
{
    if (!ft_strcmp(line, "##start"))
        return (1);
    if (!ft_strcmp(line, "##end"))
        return (3);
    return (0); // добавить какую-нибудь валидацию? на 0?
}

t_lemin *ft_init_lemin(void)
{
    t_lemin *lemin;

    if (!(lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin)))) // проверить на выделение памяти
        return (0); // выйти и почистить память
    lemin->ant_num = 0;
    lemin->line = NULL;
	lemin->rooms = NULL;
    lemin->start = NULL;
	lemin->end = NULL;
	lemin->ant_st = 0;
	lemin->ant_end = 0;
    lemin->links = NULL;
	lemin->max_bfs = 0;
    lemin->ways = NULL;
	lemin->steps = NULL;
    //t_ant		*ants;
	lemin->line = NULL;
    lemin->fd = 0;
    //lemin->fd = open("/Users/roman/Desktop/lemin/map.txt", O_RDONLY); // потом убрать
    return(lemin);
}

void ft_parse_ants(t_lemin *lemin, t_line *tmp_str)
{
    char    *line;

    get_next_line(lemin->fd, &line); // почистить и валидировать
    //lemin->ant_num = ft_atoi(line); // ???
    lemin->ant_st = ft_atoi(line); 
    tmp_str->cont = line;
    tmp_str->next = NULL;
    //ft_add_str(tmp_str, line);
}

void    ft_add_str(t_line *str, char *line)
{
    t_line *new_str;

    while(str && str->next)
        str = str->next;
    str->next = (t_line *)ft_memalloc(sizeof(t_line)); // проверить на выделение памяти
    str->next->cont = line;
    str->next->next = NULL;
}

void ft_parse_rooms(t_lemin *lemin, t_line *tmp_str)
{
    char    *line;
    int     type; // 1 - start, 2 - middle, 3 - end, 0 - невалидный случай
    t_room  *room;

    get_next_line(lemin->fd, &line); // почистить и валидировать
    ft_add_str(tmp_str, line);
    type = 2;
    while (line && (ft_is_cmt(line) || ft_is_cmd(line)
    || ft_is_room(line)))
    {
        if (ft_is_cmd(line))
            type = ft_type(line); // добавить какую-нибудь валидацию? на 0?
        else if (ft_is_room(line))
        {
            room = ft_room(line, type); // добавить валидацию комнаты
            ft_addroom(lemin, room);
            type = 2;
        } // добавить валидацию по типу
        get_next_line(lemin->fd, &line);
        ft_add_str(tmp_str, line);
    }
    lemin->line = ft_strdup(line); // проверить на выделение памяти?
}

t_lemin *ft_parser(t_line  *str)
{
    t_lemin *lemin;
    t_line  *tmp_str;    

    tmp_str = str;
    lemin = ft_init_lemin();
    ft_parse_ants(lemin, tmp_str);
    ft_parse_rooms(lemin, tmp_str);
    // валидация по наличию start и end комнаты
    ft_parse_lin(lemin, tmp_str);
    // валидация по наличию связей
    return(lemin);
}