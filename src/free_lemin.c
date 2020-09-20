#include "lemin.h"

void	free_steps(t_step	**steps)
{
	t_step	*tmp;

	if (steps)
	{
		while ((*steps))
		{
			tmp = (*steps);
			(*steps) = (*steps)->next;
			free(tmp);
		}
	}
}

void	free_links(t_link	**links)
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

void	free_rooms(t_room	**rooms)
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

void	free_ways(t_way	**ways)
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

void	free_str(t_line	**str)
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

void	free_lemin(t_lemin **lemin)
{
	if (lemin && *lemin)
	{
		free_steps(&((*lemin)->steps));
		free_ways(&((*lemin)->ways));
		free_links(&((*lemin)->links));
		free_rooms(&((*lemin)->rooms));
		if (&((*lemin)->line))
			free(((*lemin)->line)); //???
		free_str(&((*lemin)->str));
		free((*lemin));
		(*lemin) = NULL;
	}
}