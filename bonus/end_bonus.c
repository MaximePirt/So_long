/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:34:06 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 09:45:42 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_enemy(t_map *map)
{
	if (map->mlx_data.img_gun)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_gun);
	if (map->mlx_data.enemy2_sprite)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.enemy2_sprite);
	if (map->mlx_data.enemy2_sprite_move)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.enemy2_sprite_move);
}
void	destroy_bonus_p(t_map *map)
{
	if (map->mlx_data.img_floor)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_floor);
	if (map->mlx_data.img_wall)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_wall);
	if (map->mlx_data.p_sprite)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.p_sprite);
	if (map->mlx_data.img_exit)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_exit);
	if (map->mlx_data.img_compo)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_compo);
	if (map->mlx_data.img_compo_b)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_compo_b);
	if (map->mlx_data.img_floor_b)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_floor_b);
	if (map->mlx_data.img_wall_b)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_wall_b);
	if (map->mlx_data.p_sprite_b)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.p_sprite_b);
	if (map->mlx_data.img_exit_b)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_exit_b);
	if (map->mlx_data.img_exit_end)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_exit_end);
	destroy_enemy(map);
}

void	destroy_bonus(t_map *map, int which)
{
	destroy_bonus_p(map);
	if (which == 2)
	{
		if (map->mlx_data.win)
			mlx_destroy_window(map->mlx_data.mlx, map->mlx_data.win);
		if (map->mlx_data.mlx)
			mlx_destroy_display(map->mlx_data.mlx);
		ft_t_compolstclear_bonus(map->component_data->lst_component);
		map->component_data->lst_component = NULL;
		free(map->component_data);
		map->component_data = NULL;
		free_tab(map->map);
		map->map = NULL;
		free(map);
		map = NULL;
	}
}

void	send_error_bonus(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Args sent are wrong, \
			program works like ./so_long map.ber\n",
						2);
	else if (error_code == 2)
		ft_putstr_fd("FD Error check if you have perms or if file exist\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Malloc/Calloc problems, something went wrong\n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Find an unauthorised character\n", 2);
	else if (error_code == 5)
		ft_putstr_fd("You got a problem in components numbers (exit, player, \
			component)\n",
						2);
	else if (error_code == 6)
		ft_putstr_fd("MLX Init or Window init problem\n", 2);
	else if (error_code == 7)
		ft_putstr_fd("Image problems, fd or convert to png problem\n", 2);
	else if (error_code == 8)
		ft_putstr_fd("Possibilities : differents len size or unauthorisez characters ",
			2);
	else if (error_code == 9)
		ft_putstr_fd("Get_next_line failed\n", 2);
}

void	exit_func_bonus(int fd, t_map *lst, char **tab, int error_code)
{
	ft_putstr_fd("Error\n", 2);
	send_error_bonus(error_code);
	if (fd)
		close(fd);
	if (lst)
	{
		if (lst->component_data->lst_component)
			ft_t_compolstclear_bonus(lst->component_data->lst_component);
		if (lst->component_data)
			free(lst->component_data);
		if (lst->map)
			free_tab(lst->map);
		if (lst->map_fill)
			free_tab(lst->map_fill);
		free(lst);
		lst = NULL;
	}
	if (tab)
	{
		free_tab(tab);
		tab = NULL;
	}
	exit(EXIT_FAILURE);
}
