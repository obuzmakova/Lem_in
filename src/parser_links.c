/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:57:57 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 16:58:01 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
	    exit(1);
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
	if (hyphen == NULL)
		ft_error(lemin);
	if (!(st_name = ft_strsub(line, 0, ft_strlen(line) - ft_strlen(hyphen))))
		ft_error(lemin);
	if (!(end_name = ft_strsub(line, ft_strlen(line) - ft_strlen(hyphen) + 1,  ft_strlen(hyphen) - 1)))
		ft_error(lemin);
	if (!(start_room = ft_search(lemin, st_name)))
	{
		ft_strdel(&st_name);
		ft_strdel(&end_name);
		return (NULL);
	}
	if (!(end_room = ft_search(lemin, end_name)))
	{
		ft_strdel(&st_name);
		ft_strdel(&end_name);
		return (NULL);
	}
	ft_strdel(&st_name);
	ft_strdel(&end_name);
	return (ft_init_link(start_room, end_room));
}

int check_all(t_lemin *lemin)
{
    t_link *tmp_link;
    t_room *tmp_room;

    tmp_link = lemin->links;
    tmp_room = lemin->rooms;
    while(tmp_room)
    {
        while(tmp_link)
        {
            if (!(ft_strcmp(tmp_room->name, tmp_link->start->name)) ||
            !(ft_strcmp(tmp_room->name, tmp_link->end->name)))
                break;
            else
            {
                if (tmp_link->next == NULL)
                    return (0);
                tmp_link = tmp_link->next;
            }
        }
        tmp_room = tmp_room->next;
        tmp_link = lemin->links;
    }
    return (1);
}

int check_dupl(t_lemin *lemin)
{
    t_room *tmp;
    int start;
    int end;

    start = -1;
    end = -1;
    tmp = lemin->rooms;
    while (tmp)
    {
        if (tmp->type == 1)
            start++;
        if (tmp->type == 3)
            end++;
        if (tmp->type == 2 && (!ft_strcmp(tmp->name, lemin->start->name) ||
                !ft_strcmp(tmp->name, lemin->end->name)))
            return (0);
        tmp = tmp->next;
    }
    if (start == 0 && end == 0)
        return (1);
    else
        return (0);
}

int    ft_parse_lin(t_lemin *lemin)
{
    char    *line;
    t_link  *link;

    if (!ft_is_cmt(lemin->line, lemin) && ft_strlen(lemin->line) >= 1)
        {
            if (!(link = ft_link(lemin, lemin->line)))
                return (0);
			ft_add_link(lemin, link);
            // валидация связи КАКАЯ ИМЕННО ПРЕДПОЛАГАЛАСЬ?
        }
        if (get_next_line(lemin->fd, &line) != 1)
			return(0);
        ft_add_str(lemin->str, line);
	while (line)
    {
        if (!ft_is_cmt(line, lemin) && ft_strlen(line) >= 1)
        {
            if (!(link = ft_link(lemin, line)))
            {
				//ft_strdel(&line);
				return (0);
			}
			ft_add_link(lemin, link);
            // валидация связи КАКАЯ ИМЕННО ПРЕДПОЛАГАЛАСЬ?
        }
        get_next_line(lemin->fd, &line);
        ft_add_str(lemin->str, line);
    }
    if (!check_all(lemin))
        return (0);
    if (!check_dupl(lemin))
        return (0);
    return(1);
}
