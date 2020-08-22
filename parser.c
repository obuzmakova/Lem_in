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
	//int			start;
	//int 		end;
    lemin->links = NULL;
	lemin->max_bfs = 0;
	//t_path		*paths;
	//t_location	*locations;
	//t_ant		*ants;
	lemin->line = NULL;
    lemin->fd = open("/Users/roman/Desktop/lemin/mini_map.txt", O_RDONLY); // потом убрать
    return(lemin);
}

void ft_parse_ants(t_lemin *lemin)
{
    char    *line;

    get_next_line(lemin->fd, &line); // почистить и валидировать
    lemin->ant_num = ft_atoi(line);
}

void ft_parse_rooms(t_lemin *lemin)
{
    char    *line;
    int     type; // 1 - start, 2 - middle, 3 - end, 0 - невалидный случай
    t_room  *room;

    get_next_line(lemin->fd, &line); // почистить и валидировать
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
    }
    lemin->line = ft_strdup(line); // проверить на выделение памяти?
}

t_lemin *ft_parser()
{
    t_lemin *lemin;

    lemin = ft_init_lemin();
    ft_parse_ants(lemin);
    ft_parse_rooms(lemin);
    // валидация по наличию start и end комнаты
    ft_parse_lin(lemin);
    // валидация по наличию связей
    return(lemin);
}