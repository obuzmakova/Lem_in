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

int			ft_valid_str(char *line, t_lemin *lemin)
{
	return (ft_is_cmt(line, lemin) || ft_is_cmd(line) || ft_is_room(line));
}

int			link_help(t_lemin *lemin, t_link *link, char *line)
{
	if (!(link = ft_link(lemin, line)))
		return (0);
	ft_add_link(lemin, link);
	return (1);
}

t_room		*ft_search(t_lemin *lemin, char *name)
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

t_link		*ft_init_link(t_room *start, t_room *end)
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
