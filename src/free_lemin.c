/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:27:59 by mleticia          #+#    #+#             */
/*   Updated: 2020/10/01 10:28:03 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_links(t_link **links)
{
	t_link	*tmp;

	if (links)
	{
		while ((*links))
		{
			tmp = (*links);
			(*links) = (*links)->next;
			free(tmp);
		}
	}
}

void		free_rooms(t_room **rooms)
{
	t_room	*tmp;

	if (rooms)
	{
		while ((*rooms))
		{
			tmp = (*rooms);
			(*rooms) = (*rooms)->next;
			free(tmp->name);
			free(tmp);
		}
	}
}

void		free_ways(t_way **ways)
{
	t_way	*tmp;

	if (ways)
	{
		while ((*ways))
		{
			tmp = (*ways);
			(*ways) = (*ways)->next;
			free_links(&(tmp->link));
			free(tmp);
		}
	}
}

void		free_str(t_line **str)
{
	t_line	*tmp;
	t_line	*line;

	line = (*str);
	while (line)
	{
		tmp = line;
		line = line->next;
		free(tmp->cont);
		free(tmp);
	}
	(*str) = NULL;
}

void		free_lemin(t_lemin **lemin)
{
	if (lemin && *lemin)
	{
		free_steps(&((*lemin)->steps));
		free_ways(&((*lemin)->ways));
		free_links(&((*lemin)->links));
		free_rooms(&((*lemin)->rooms));
		if (&((*lemin)->line))
			free(((*lemin)->line));
		free_str(&((*lemin)->str));
		free((*lemin));
		(*lemin) = NULL;
	}
}
