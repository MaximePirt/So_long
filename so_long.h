/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:50 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/30 09:01:26 by mpierrot         ###   ########.fr       */
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

typedef struct s_player
{
	int					player;
	int					x;
	int					y;
}						t_player;

typedef struct s_exit
{
	int					exit;
	int					x;
	int					y;
}						t_exit;

typedef struct s_component
{
	int					is_loot;
	int					x;
	int					y;
	struct s_component	*next;
}						t_component;

typedef struct s_components
{
	t_component			*lst_component;
	int					hm_component;
}						t_components;

typedef struct s_img
{
	int					x;
	int					y;
	struct s_img		*next;
}						t_img;

typedef struct s_mlx
{
	void				*img_floor;
	void				*img_wall;
	void				*img_compo;
	void				*img_exit;
	void				*p_sprite;
	int					img_w;
	int					img_h;
	void				*mlx;
	void				*win;
	struct s_mlx		*next;
}						t_mlx;

typedef struct s_map
{
	t_player			player_data;
	t_exit				exit_data;
	t_components		*component_data;
	t_img				img_data;
	t_mlx				mlx_data;
	char				**map_fill;
	char				**map;
	// char				**tab;
	char				*file_name;
	char				*str;
	size_t				line_len;
	int					col;
	int					line;
	int					size_x;
	int					size_y;
	int					i;
	int					j;
	int					fd;
	size_t				size;
	struct s_map		*next;
}						t_map;

t_map					*init_t_map(char *str);

/////////// Parsing utils ///////////
int						check_name(char *file);
void					check_size(t_map *map);
// fill_w_water
t_map					*preptoflood(char *str);
// int					flood_fill(char **tab, t_map *map, char fill);
void					flood_fill(t_map *map, int x, int y);

// exit
void					exit_func(int fd, t_map *lst, char *str, char **tab);

#endif