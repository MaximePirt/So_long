/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:34:03 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 04:43:51 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_opening(t_map *map)
{
	int	fd;

	(void)fd;
	(void)map;
	fd = open("textures/cons.png", O_RDONLY);
	if (fd == -1)
		exit_func(0, map, NULL, 7);
	close(fd);
	fd = open("textures/floor.png", O_RDONLY);
	if (fd == -1)
		exit_func(0, map, NULL, 7);
	close(fd);
	fd = open("textures/wall.png", O_RDONLY);
	if (fd == -1)
		exit_func(0, map, NULL, 7);
	close(fd);
	fd = open("sprites/player.png", O_RDONLY);
	if (fd == -1)
		exit_func(0, map, NULL, 7);
	close(fd);
	fd = open("sprites/exit.png", O_RDONLY);
	if (fd == -1)
		exit_func(0, map, NULL, 7);
	close(fd);
}

void	init_img(t_map *map)
{
	check_opening(map);
	map->mlx_data.img_compo = mlx_png_file_to_image(map->mlx_data.mlx,
			"textures/cons.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.img_floor = mlx_png_file_to_image(map->mlx_data.mlx,
			"textures/floor.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.img_wall = mlx_png_file_to_image(map->mlx_data.mlx,
			"textures/wall.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.p_sprite = mlx_png_file_to_image(map->mlx_data.mlx,
			"sprites/player.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.img_exit = mlx_png_file_to_image(map->mlx_data.mlx,
			"sprites/exit.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	if (!map->mlx_data.img_floor || !map->mlx_data.img_wall
		|| !map->mlx_data.img_exit || !map->mlx_data.p_sprite
		|| !map->mlx_data.img_compo)
	{
		destroy(map, 1);
		exit_func(0, map, NULL, 7);
	}
}

void	forest(t_map *map, int i, int j)
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
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'E')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_exit, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
}

void	image_in_wdw(t_map *map)
{
	int	i;
	int	j;

	init_img(map);
	i = 0;
	j = 0;
	while (map->map[j])
	{
		while (map->map[j][i] && map->map[j][i] != '\n')
		{
			forest(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}
