#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
#include <stdio.h> // потом убрать
#include <fcntl.h> // потом убрать?

typedef struct		s_room
{
	char			*name;
	int				type;
	int				bfs_lvl;
	int				inp_lin;
	int				out_lin;
	int				ant_num;
	struct s_room	*next;
}					t_room;

typedef struct			s_link
{
	t_room				*start;
	t_room				*end;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;

typedef struct  s_lemin
{
	int         ant_num;
	t_room		*rooms;
    t_room		*start;
	t_room		*end;
	//int			start;
	//int 		end;
	t_link		*links;
	//int			bfs_level;
	//t_path		*paths;
	//t_location	*locations;
	//t_ant		*ants;
	char		*line; // последняя сгнленная строка
	int			fd;
}						t_lemin;

typedef struct			s_tail
{
	t_room				*room;
	struct s_tail		*next;
}						t_tail;

t_lemin *ft_parser();
t_lemin *ft_init_lemin(void);
void	ft_parse_ants(t_lemin *lemin);
void	ft_parse_rooms(t_lemin *lemin);
int		ft_is_cmt(char *line);
int		ft_is_cmd(char *line);
int		ft_is_room(char *line);
t_room	*ft_room(char *line, int type);
void	ft_addroom(t_lemin *lemin, t_room *room);
void    ft_parse_lin(t_lemin *lemin);
t_room	*ft_search(t_lemin *lemin, char *name);
t_link  *ft_init_link(t_room *start, t_room *end);
void	ft_add_link(t_lemin *lemin, t_link *link);
int		ft_len_arr(char **arr);
int		ft_is_plint(char *str);
void    ft_print(t_lemin *lemin);
void    ft_print_room(t_lemin *lemin);
void    ft_print_links(t_lemin *lemin);
void    bfs(t_lemin *lemin);
t_tail  *create_el_tail(t_room *room);
void    add_el_tail(t_tail **tail, t_tail *el);
t_tail  *head_tail(t_tail **tail);
void    add_neighb(t_lemin *lemin, t_tail **tail, t_room *room);

#endif
