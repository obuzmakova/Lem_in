/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 17:39:24 by Student           #+#    #+#             */
/*   Updated: 2020/06/18 17:39:27 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef struct s_link
{
	char *name; //имя комнаты
	char **nodes; //все смежные комнаты, т.е. в которые есть направленная связь из name
	struct s_link *next; //указатнль на следующий перечень, без привязки к связям текущей комнаты
}               t_link;

typedef struct s_file
{
	int ants; //кол-во муравьев на старте
	char *start; //комната старта
	char *end; //комната конца
	char **rooms; //перечень комнат?
	t_link *links; //перечень ребер каждой из комнат
}               t_file;

void		free_all(char **str)
{
	int		i;

	i = -1;
	if (str && str[0])
	{
		while (str[++i])
			;
		while (--i >= 0)
		{
			free(str[i]);
			str[i] = NULL;
		}
		free(str);
		str = NULL;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void parse_links(t_file *file, char *str)
{
	t_file *tmp;
	char **info;
	int i;

	i = 0;
	tmp = file;
	info = ft_strsplit(str, '-');
	if (tmp->links->name == NULL)
	{
		file->links->name = ft_strdup(info[0]); //записываем имя вершины
		file->links->nodes[i] = ft_strdup(info[1]); //имя смежной (слинкованной) вершины
		file->links->next = NULL;
	}
	else
		{
		if (ft_strcmp(tmp->links->name, info[0]) == 0) //если имя текущей вершины совпадает с прочитанным, то смежную записываем в перечень
		{
			while (tmp->links->nodes[i] != NULL)
				i++;
			file->links->nodes[i] = ft_strdup(info[1]);
		}
		else
		{
			while (tmp->links->next)
				tmp->links = tmp->links->next;
			//тут будет продолжение
		}
	}
	free_all(info);
}

int main (int ac, char **av)
{
	t_file *file;
	char *str;
	char **info;

	file = (t_file*)ft_memalloc(sizeof(t_file)); // выделение и зануление памяти начальной структуры
	file->links = (t_link*)ft_memalloc(sizeof(t_link)); //выделение и зануление памяти под перечень ребер
	get_next_line(0, &str); //читаем первую строку
	file->ants = ft_atoi(str); //пока что сразу записываем кол-во муравьеа из нее
	ft_strdel(&str); //чистим прочитанное
	while (get_next_line(0, &str) != 0) //далее построчное чтение в цикле
	{
		if (ft_strequ("##start", str)) //в случае ##start запись из последующей строки инфо о стартовой комнате
		{
			ft_strdel(&str);
			get_next_line(0, &str);
			info = ft_strsplit(str, ' ');
			file->start = ft_strdup(info[0]); //записываем только название
			free_all(info);
		}
		else if (ft_strequ("##end", str)) //аналогично о финальной
		{
			ft_strdel(&str);
			get_next_line(0, &str);
			info = ft_strsplit(str, ' ');
			file->end = ft_strdup(info[0]); //записываем только название
			free_all(info);
		}
		else if (ft_memchr(str, '-', ft_strlen(str))) //если в строке в качестве разделителя видим '-', то отправляемся записывать инфо о ребре
			parse_links(file, str);
		//else
		//	parse_rooms(file, str);
		ft_strdel(&str);
	}
	printf("ants = %i\n", file->ants);
	printf("start = %s\n", file->start);
	printf("end = %s\n", file->end);
	return (0);
}
