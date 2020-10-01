/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:26:56 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 15:27:02 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_num(char *s, int *n)
{
	int		i;
	char	*num;

	if (!*s || !((*s >= '0' && *s <= '9') || *s == '-' || *s == '+'))
		return (0);
	*n = ft_atoi(s);
	i = (*s == '-' || *s == '+') ? 0 : -1;
	while (s[++i] == '0')
		;
	if (!(num = ft_itoa(*n)) ||
		(*s == '-' && ft_strncmp(num + 1, s + i, ft_strlen(num) - 1)) ||
		(*s != '-' && ft_strncmp(num, s + (*n ? i : i - 1), ft_strlen(num))) ||
		(*s == '-' && !*n))
	{
		num ? free(num) : 0;
		return (0);
	}
	i += (*n ? ft_strlen(num) : 0) - (*s == '-' ? 1 : 0);
	free(num);
	return (i);
}

int			ft_parse_ants(t_lemin *lemin)
{
	char	*line;

	if (get_next_line(lemin->fd, &line) != 1 || !(ft_strlen(line)))
	{
		ft_strdel(&line);
		return (0);
	}
	lemin->ant_st = ft_atoi(line);
	if (!(check_num(line, &lemin->ant_st)))
	{
		ft_strdel(&line);
		return (0);
	}
	if (lemin->ant_st <= 0)
	{
		ft_strdel(&line);
		return (0);
	}
	if (!(lemin->str = (t_line*)ft_memalloc(sizeof(t_line))))
	{
		ft_strdel(&line);
		return (0);
	}
	if (!(lemin->str->cont = ft_strdup(line)))
	{
		ft_strdel(&line);
		return (0);
	}
	lemin->str->next = NULL;
	ft_strdel(&line);
	return (1);
}

int			ft_parse_rooms(t_lemin *lemin)
{
	char	*line;
	int		type;
	t_room	*room;

	if (get_next_line(lemin->fd, &line) != 1)
		return (0);
	ft_add_str(lemin->str, line);
	type = 2;
	while (line && (ft_is_cmt(line, lemin)
	|| ft_is_cmd(line) || ft_is_room(line)))
	{
		if (ft_is_cmd(line))
			type = ft_type(line);
		else if (ft_is_room(line))
		{
			room = ft_room(line, type);
			ft_addroom(lemin, room);
			type = 2;
		}
		if (!get_next_line(lemin->fd, &line))
			return (0);
		ft_add_str(lemin->str, line);
	}
	if (!(lemin->line = ft_strdup(line)))
		return (0);
	if (!ft_strchr(line, '-'))
		return (0);
	return (1);
}

int			valid_start_end(t_lemin *lemin)
{
	if (lemin->start && lemin->end)
	{
		if (!ft_strlen(lemin->start->name) || !ft_strlen(lemin->end->name))
			return (0);
	}
	else
		return (0);
	return (1);
}

int			ft_parser(t_lemin *lemin)
{
	ft_init_lemin(lemin);
	if (!ft_parse_ants(lemin))
		ft_error(lemin);
	if (!ft_parse_rooms(lemin))
		ft_error(lemin);
	if (!valid_start_end(lemin))
		ft_error(lemin);
	if (!ft_parse_lin(lemin))
		ft_error(lemin);
	return (1);
}
