#ifndef MAP_H
# define MAP_H

# include "../so_long.h"

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}	t_mapcheckerdata;

#endif