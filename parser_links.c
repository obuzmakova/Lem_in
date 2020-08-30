#include "lemin.h"

void	ft_add_link(t_lemin *lemin, t_link *link)
{
	t_link	*tmp;

	tmp = lemin->links;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = link;
	}
	else
		lemin->links = link;
}

t_link  *ft_init_link(t_room *start, t_room *end)
{
	t_link	*link;

	link = (t_link *)ft_memalloc(sizeof(t_link)); // проверить на выделение памяти
	link->start = start;
	link->end = end;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

t_room	*ft_search(t_lemin *lemin, char *name)
{
	t_room	*tmp;

	tmp = lemin->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_link  *ft_link(t_lemin *lemin, char *line)
{
    char	*hyphen;
	char	*st_name;
	char	*end_name;
	t_room	*start_room;
	t_room	*end_room;

    hyphen = ft_strchr(line, '-');
    st_name = ft_strsub(line, 0, ft_strlen(line) - ft_strlen(hyphen)); // проверить на выделение памяти
    end_name = ft_strsub(line, ft_strlen(line) - ft_strlen(hyphen) + 1,  ft_strlen(hyphen) - 1); // проверить на выделение памяти
    start_room = ft_search(lemin, st_name);
	end_room = ft_search(lemin, end_name);
    free(st_name);
	free(end_name);
    if (start_room && end_room)
		return (ft_init_link(start_room, end_room));
    return (NULL); // возможно нужна какая-то валидация?
}

int    ft_parse_lin(t_lemin *lemin, t_line *tmp_str)
{
    char    *line;
    t_link  *link;

    line = ft_strdup(lemin->line);
    while (line)
    {
        if (!ft_is_cmt(line) && ft_strlen(line) >= 1)
        {
            link = ft_link(lemin, line); // какая-то валидация?
            ft_add_link(lemin, link);
            // валидация связи
        }
        get_next_line(lemin->fd, &line);
        ft_add_str(tmp_str, line);
    }
    return(1);
}
