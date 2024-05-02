/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:50 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/02 05:14:05 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MacroLibX/includes/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

///////////////
# include <stdio.h>
//////////////
# define WIDTH 32
# define HEIGHT 32

typedef struct s_player
{
	int						player;
	int						x;
	int						y;
}							t_player;

typedef struct s_exit
{
	int						exit;
	int						x;
	int						y;
}							t_exit;

typedef struct s_componentlst
{
	int						is_loot;
	int						x;
	int						y;
	struct s_componentlst	*next;
}							t_componentlst;

typedef struct s_components
{
	t_componentlst			*lst_component;
	int						hm_component;
}							t_components;

typedef struct s_img
{
	int						x;
	int						y;
	struct s_img			*next;
}							t_img;

typedef struct s_mlx
{
	void					*img_floor;
	void					*img_wall;
	void					*img_compo;
	void					*img_exit;
	void					*p_sprite;
	int						img_w;
	int						img_h;
	int						w_pov;
	void					*mlx;
	void					*win;
	struct s_mlx			*next;
}							t_mlx;

typedef struct s_map
{
	t_player				player_data;
	t_exit					exit_data;
	t_components			*component_data;
	t_img					img_data;
	t_mlx					mlx_data;
	char					**map_fill;
	char					**map;
	char					*file_name;
	char					*str;
	size_t					line_len;
	int						col;
	int						line;
	int						size_x;
	int						size_y;
	int						i;
	int						j;
	int						fd;
	int						score;
	size_t					size;
	struct s_map			*next;
}							t_map;

/////////// Parsing utils ///////////
int							check_name_bonus(char *file);
void						check_size_bonus(t_map *map);
// fill_w_water
t_map						*preptoflood_bonus(char *str);
void						where_start_fill_bonus(t_map *map);
void						flood_fill_bonus(t_map *map, int x, int y);
void						fill_struc_compo_bonus(t_map *map, char c, int x,
								int y);
void						filltab_bonus(t_map *map);

// fill_w_water_utils
int							hm_compo_bonus(char **tab);
void						clean_flood_bonus(t_map *map);
void						copy_map_to_mapfill_bonus(t_map *map);

// window-mlx
void						image_in_wdw_bonus(t_map *map);
void						init_img_bonus(t_map *map);
void						change_pov(t_map *map);
// lst_func
void						ft_lstadd_back_cmpnt_bonus(t_componentlst **lst,
								t_componentlst *new);
t_componentlst				*ft_datalstlast_cmpnt_bonus(t_componentlst *lst);
t_componentlst				*ft_lstnew_cmpnt_bonus(t_componentlst *content,
								int x, int y);
void						ft_t_compolstclear_bonus(t_componentlst *lst);

// lst_func_init_clear
t_map						*init_t_map_bonus(char *str);
void						ft_t_compolstclear_bonus(t_componentlst *lst);

// key_mvmt
void						move_up_bonus(t_map *map);
void						move_down_bonus(t_map *map);
void						move_left_bonus(t_map *map);
void						move_right_bonus(t_map *map);
int							key_hook_bonus(int key, void *mlx);

// end.c
void						destroy_bonus(t_map *map, int which);
void						exit_func_bonus(int fd, t_map *lst, char **tab);

// main.c
int							window_hook_bonus(int event, void *param);
void						check_components_bonus(t_map *map);

// to delete
void						print_map(t_map *map);

#endif