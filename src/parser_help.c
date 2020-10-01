/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:57:39 by mleticia          #+#    #+#             */
/*   Updated: 2020/09/06 16:57:44 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_len_arr(char **arr)
{
	int		i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

int			ft_is_plint(char *str)
{
	int		num;

	if (str && ft_strlen(str) >= 1)
	{
		num = ft_atoi(str);
		if (num >= 0 && num <= 2147483647)
			return (1);
	}
	return (0);
}

int			ft_type(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	if (!ft_strcmp(line, "##end"))
		return (3);
	return (0);
}

int			ft_init_lemin(t_lemin *lemin)
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
	lemin->line = NULL;
	lemin->fd = 0;
	lemin->str = NULL;
	return (1);
}

void		ft_add_str(t_line *str, char *line)
{
	while (str && str->next)
		str = str->next;
	if (!(str->next = (t_line *)ft_memalloc(sizeof(t_line))))
		exit(1);
	str->next->cont = line;
	str->next->next = NULL;
}
