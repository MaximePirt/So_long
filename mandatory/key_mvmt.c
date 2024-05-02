/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mvmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:28:18 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/02 01:56:38 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->map[(map->col - 1)][map->line] == '1')
		return ;
	else
	{
		map->player_data.y -= 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y + 1][map->player_data.x] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->col--;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}

void	move_down(t_map *map)
{
	if (map->map[(map->col + 1)][map->line] == '1')
		return ;
	else
	{
		map->player_data.y += 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y - 1][map->player_data.x] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->col++;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}

void	move_left(t_map *map)
{
	if (map->map[map->col][map->line - 1] == '1')
		return ;
	else
	{
		map->player_data.x -= 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y][map->player_data.x + 1] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->line--;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}

void	move_right(t_map *map)
{
	if (map->map[map->col][map->line + 1] == '1')
		return ;
	else
	{
		map->player_data.x += 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y][map->player_data.x - 1] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->line++;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}

int	key_hook(int key, void *mlx)
{
	t_map	*map;

	map = mlx;
	if (key == 41)
		mlx_loop_end(map->mlx_data.mlx);
	if (key == 26 || key == 82)
		move_up(map);
	if (key == 22 || key == 81)
		move_down(map);
	if (key == 4 || key == 80)
		move_left(map);
	if (key == 7 || key == 79)
		move_right(map);
	if (key == 19)
		return (0);
	return (0);
}
