/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:34:03 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 09:39:29 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_opening_enemy(t_map *map)
{
	int	fd;

	fd = open("bonus/sprites/enemy.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/sprites/enemy2.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/sprites/enemy2_move.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	fd = open("bonus/textures/gun.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
}

static void	check_opening_bonus(t_map *map)
{
	int	fd;

	fd = open("bonus/textures/cons.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/textures/floor.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/textures/wall.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/sprites/player.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/sprites/exit.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	fd = open("bonus/sprites/exit.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
}

static void	check_opening_bonus_p(t_map *map)
{
	int	fd;

	fd = open("bonus/textures/consp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/textures/floorp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/textures/wallp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/sprites/playerp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
	fd = open("bonus/sprites/exitp.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	fd = open("bonus/sprites/exit_end.png", O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL, 7);
	close(fd);
}
void	init_img_enemy(t_map *map)
{
	check_opening_enemy(map);
	map->mlx_data.enemy_sprite = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/enemy.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.enemy2_sprite = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/enemy2.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.enemy2_sprite_move = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/enemy2_move.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_gun = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/gun.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	if (!map->mlx_data.enemy2_sprite || !map->mlx_data.enemy2_sprite_move
		|| !map->mlx_data.enemy_sprite)
	{
		destroy_bonus(map, 1);
		exit_func_bonus(0, map, NULL, 7);
	}
}

void	init_img_bonus(t_map *map)
{
	check_opening_bonus(map);
	init_img_enemy(map);
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
	map->mlx_data.img_exit_end = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/exit_end.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	if (!map->mlx_data.img_floor || !map->mlx_data.img_wall
		|| !map->mlx_data.img_exit || !map->mlx_data.p_sprite
		|| !map->mlx_data.img_compo)
	{
		destroy_bonus(map, 1);
		exit_func_bonus(0, map, NULL, 7);
	}
	map->mlx_data.w_pov = 0;
}

void	init_img_bonus_p(t_map *map)
{
	check_opening_bonus_p(map);
	init_img_enemy(map);
	map->mlx_data.img_compo_b = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/consp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_floor_b = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/floorp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_wall_b = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/textures/wallp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.p_sprite_b = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/playerp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	map->mlx_data.img_exit_b = mlx_png_file_to_image(map->mlx_data.mlx,
			"bonus/sprites/exitp.png", &map->mlx_data.img_w,
			&map->mlx_data.img_h);
	if (!map->mlx_data.img_floor_b || !map->mlx_data.img_wall_b
		|| !map->mlx_data.img_exit_b || !map->mlx_data.p_sprite_b
		|| !map->mlx_data.img_compo_b)
	{
		destroy_bonus(map, 1);
		exit_func_bonus(0, map, NULL, 7);
	}
	map->mlx_data.w_pov = 1;
}

void	forest_bonus_end(t_map *map, int i, int j)
{
	if (map->map[j][i] == 'K')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.enemy_sprite, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'N')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.enemy2_sprite, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'G')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_gun, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'E' && map->component_data->hm_component < 1)
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_exit_end, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_exit, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
}

void	forest_bonus_p(t_map *map, int i, int j)
{
	if (map->map[j][i] == '1')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_wall_b, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == '0')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_floor_b, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'C')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_compo_b, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'P')
	{
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_floor_b, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
		put_player(map);
	}
	else
		forest_bonus_end(map, i, j);
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
		put_player(map);
	}
	else
		forest_bonus_end(map, i, j);
}

void	change_pov(t_map *map)
{
	char	c;

	c = map->map[map->player_data.y][map->player_data.x];
	map->map[map->player_data.y][map->player_data.x] = 'P';
	if (map->mlx_data.w_pov == 0)
		map->mlx_data.w_pov = 1;
	else
		map->mlx_data.w_pov = 0;
	mlx_clear_window(map->mlx_data.mlx, map->mlx_data.win);
	image_in_wdw_bonus(map);
	map->map[map->player_data.y][map->player_data.x] = c;
}

void	image_in_wdw_bonus(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[j])
	{
		while (map->map[j][i] && map->map[j][i] != '\n')
		{
			if (map->mlx_data.w_pov == 1)
				forest_bonus_p(map, i, j);
			else
				forest_bonus(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}
