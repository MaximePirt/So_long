/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:50 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/29 05:32:05 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MacroLibX/includes/mlx.h"
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/////////////////////////////////////////////
# include "stdio.h"
////////////////////////////////////////////

# define WIDTH 64
# define HEIGHT 64
typedef struct s_map
{
	int				col;
	int				line;
	int				size_x;
	int				size_y;
	int				components;
	int				player;
	int				exit;
	char			**tab;
	int				i;
	int				j;
	size_t			size;
	int				fd;
	void			*img_floor;
	void			*img_wall;
	void			*img_compo;
	void			*img_exit;
	int				img_w;
	int				img_h;
	void			*p_sprite;
	void			*win;
	struct s_map	*next;
}					t_map;

void				init_t_map(t_map *map, char *str);

/////////// Parsing utils ///////////
int					check_name(char *file);
int					check_size(char *file);
// fill_w_water
t_map				*preptoflood(char *str);
// int					flood_fill(char **tab, t_map *map, char fill);
void				flood_fill(t_map *map, int x, int y);

// exit
void				exit_func(int fd, t_map *lst, char *str, char **tab);
#endif