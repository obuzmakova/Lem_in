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

#include "./include/lemin.h"

int     ft_type(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	if (!ft_strcmp(line, "##end"))
		return (3);
	return (0);
}

int ft_init_lemin(t_lemin *lemin)
{
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
	lemin->fd = open("/Users/romannezgovorov/Desktop/Lem_in/maps/our_old_maps/mini_map.txt", O_RDONLY); // потом убрать
	return(1);
}

int ft_parse_ants(t_lemin *lemin, t_line *tmp_str)
{
	char    *line;

	if (get_next_line(lemin->fd, &line) != 1)
		exit(1);
	//lemin->ant_num = ft_atoi(line); // НАВЕРНОЕ ЭТО МОЖНО УДАЛИТЬ УЖЕ?
	lemin->ant_st = ft_atoi(line);
	if (lemin->ant_st <= 0)
		return (0);
	if (!(tmp_str->cont = ft_strdup(line)))
		exit(1);
	tmp_str->next = NULL;
	ft_strdel(&line);
	return (1);
	//ft_add_str(tmp_str, line); // НАВЕРНОЕ ЭТО МОЖНО УДАЛИТЬ УЖЕ?
}

void    ft_add_str(t_line *str, char *line)
{
	while(str && str->next)
		str = str->next;
	if (!(str->next = (t_line *)ft_memalloc(sizeof(t_line))))
		exit(1);
	str->next->cont = line;
	str->next->next = NULL;
}

int ft_parse_rooms(t_lemin *lemin, t_line *tmp_str)
{
	char    *line;
	int     type; // 1 - start, 2 - middle, 3 - end, 0 - невалидный случай
	t_room  *room;

	if (get_next_line(lemin->fd, &line) != 1)
		exit(1);
	ft_add_str(tmp_str, line);
	type = 2;
	while (line && (ft_is_cmt(line, lemin) || ft_is_cmd(line) || ft_is_room(line)))
	{
		if (ft_is_cmd(line))
			type = ft_type(line); // добавить какую-нибудь валидацию? на 0? НОЛЬ В КАЧЕСТВЕ ЧЕГО?
		else if (ft_is_room(line))
		{
			room = ft_room(line, type); // добавить валидацию комнаты А ИМЕННО? ВРОДЕ ВСЕ ОК ТЕПЕРЬ?
			ft_addroom(lemin, room);
			type = 2;
		} // добавить валидацию по типу ТОЖЕ НЕ ПОНЯЛА
		get_next_line(lemin->fd, &line);
		ft_add_str(tmp_str, line);
	}
	if (!(lemin->line = ft_strdup(line)))
		exit(1);
	if (!ft_strchr(line, '-'))
		ft_error(lemin);
	//ft_strdel(&line);
	return (1);
}

int valid_start_end(t_lemin *lemin)
{
	if (lemin->start && lemin->end)
	{
		if (!ft_strlen(lemin->start->name) || !ft_strlen(lemin->end->name))
			return (0);
	}
	else
		return (0);
	return(1);
}

int ft_parser(t_lemin *lemin, t_line *str)
{
	ft_init_lemin(lemin);
	if (!ft_parse_ants(lemin, str))
		ft_error(lemin);
	if (!ft_parse_rooms(lemin, str))
		ft_error(lemin);
	if(!valid_start_end(lemin))
		ft_error(lemin);
	if (!ft_parse_lin(lemin, str))
		ft_error(lemin);
	// валидация по наличию связей ЧЕКНИ, ПЛИЗ, СДЕЛАЛА ЛИ Я ТО ЧТО ТЫ ИМЕЛА ТУТ ВВИДУ
	return (1);
}
