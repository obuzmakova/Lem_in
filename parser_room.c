#include "lemin.h"

int ft_is_cmt(char *line)
{
    if (line)
	{
		if (ft_strlen(line) && !ft_is_cmd(line)
			&& !ft_strncmp(line, "#", 1))
			return (1);
	}
	return (0);
}

int ft_is_cmd(char *line)
{
    if (line)
	{
		if (ft_strlen(line) >= 2
        && !ft_strncmp(line, "##", 2))
			return (1);
	}
	return (0);
}

int ft_is_room(char *line)
{
    char	**tab;

	if (!(tab = ft_strsplit(line, ' '))) // невалидный случай
		return (0);
	if (ft_len_arr(tab) == 3)
	{
        if (tab[0] && ft_strlen(tab[0]))
        {
            if (tab[0][0] != '#' && ft_is_plint(tab[1])
			&& ft_is_plint(tab[2])) // зафришить tab
                return (1);
        }
	}
	// зафришить tab
	return (0);
}

t_room *ft_room(char *line, int type)
{
    char    **tab;
	t_room	*room;

    tab = ft_strsplit(line, ' '); // зафришить
    room = (t_room *)ft_memalloc(sizeof(t_room)); // проверить на выделение памяти
    room->name = ft_strdup(tab[0]); // проверить на выделение памяти?
    room->type = type;
    room->bfs_lvl = -1;
    room->inp_lin = 0;
    room->out_lin = 0;
    room->ant_num = -1;
    room->next = NULL;
	return (room);
}

void ft_addroom(t_lemin *lemin, t_room *room)
{
    t_room *tmp;

	if ((tmp = lemin->rooms))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
	else
		lemin->rooms = room;
	if (room->type == 1)
		lemin->start = room;
	else if (room->type == 3)
		lemin->end = room;
}