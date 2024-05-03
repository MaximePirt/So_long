/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:34:03 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/03 22:24:31 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_opening_bonus(t_map *map)
{
	int	fd;

	fd = open("bonus/textures/cons.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/textures/floor.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/textures/wall.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/sprites/player.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/sprites/exit.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
}

void	check_opening_bonus_p(t_map *map)
{
	int	fd;

	fd = open("bonus/textures/consp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/textures/floorp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/textures/wallp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/sprites/playerp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
	fd = open("bonus/sprites/exitp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	close(fd);
}

void	init_img_bonus(t_map *map)
{
	check_opening_bonus(map);
	destroy_bonus(map, 1);
	map->mlx_data.img_compo = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/cons.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_floor = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/floor.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_wall = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/wall.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.p_sprite = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/player.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_exit = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/exit.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	if (!map->mlx_data.img_floor || !map->mlx_data.img_wall
		|| !map->mlx_data.img_exit || !map->mlx_data.p_sprite
		|| !map->mlx_data.img_compo)
	{
		destroy_bonus(map, 1);
		exit_func_bonus(0, map, NULL);
	}
	map->mlx_data.w_pov = 0;
}

void	init_img_bonus_p(t_map *map)
{
	destroy_bonus(map, 1);
	map->mlx_data.img_compo = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/consp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_floor = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/floorp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_wall = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/wallp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.p_sprite = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/playerp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_exit = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/exitp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	if (!map->mlx_data.img_floor || !map->mlx_data.img_wall
		|| !map->mlx_data.img_exit || !map->mlx_data.p_sprite
		|| !map->mlx_data.img_compo)
	{
		destroy_bonus(map, 1);
		exit_func_bonus(0, map, NULL);
	}
	map->mlx_data.w_pov = 1;
}

void	forest_bonus(t_map *map, int i, int j)
{
	if (map->map[j][i] == '1')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_wall, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == '0')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_floor, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'C')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_compo, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'P')
	{
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_floor, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	}
	else if (map->map[j][i] == 'E')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_exit, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
}

void	change_pov(t_map *map)
{
	char	c;

	c = map->map[map->player_data.y][map->player_data.x];
	map->map[map->player_data.y][map->player_data.x] = 'P';
	if (map->mlx_data.w_pov == 0)
	{
		init_img_bonus_p(map);
		map->mlx_data.w_pov = 1;
	}
	else
	{
		init_img_bonus(map);
		map->mlx_data.w_pov = 0;
	}
	mlx_clear_window(map->mlx_data.mlx, map->mlx_data.win);
	image_in_wdw_bonus(map);
	map->map[map->player_data.y][map->player_data.x] = c;
}

void	image_in_wdw_bonus(t_map *map)
{
	int	i;
	int	j;

	if (!map->mlx_data.w_pov)
	{
		init_img_bonus(map);
		map->mlx_data.w_pov = 0;
	}
	i = 0;
	j = 0;
	while (map->map[j])
	{
		while (map->map[j][i] && map->map[j][i] != '\n')
		{
			forest_bonus(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}
