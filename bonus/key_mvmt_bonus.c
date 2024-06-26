/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mvmt_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:28:18 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 06:13:00 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_exit_or_floor(t_map *map)
{
	if (map->map[map->player_data.y + 1][map->player_data.x] == 'E')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_exit, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	else
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_floor, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
}

void	put_player(t_map *map)
{
	if (map->mlx_data.w_pov == 0)
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	else
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite_b, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
}

void	move_up_bonus(t_map *map)
{
	if (map->map[(map->col - 1)][map->line] == '1')
		return ;
	else
	{
		map->player_data.y -= 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components_bonus(map);
		put_exit_or_floor(map);
		if (map->component_data->hm_component < 1
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->col--;
		put_player(map);
	}
	map->score++;
	print_score(map);
}

void	move_down_bonus(t_map *map)
{
	if (map->map[(map->col + 1)][map->line] == '1')
		return ;
	else
	{
		map->player_data.y += 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components_bonus(map);
		put_exit_or_floor(map);
		if (map->component_data->hm_component < 1
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->col++;
		put_player(map);
	}
	map->score++;
	print_score(map);
}

void	move_left_bonus(t_map *map)
{
	if (map->map[map->col][map->line - 1] == '1')
		return ;
	else
	{
		map->player_data.x -= 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components_bonus(map);
		put_exit_or_floor(map);
		if (map->component_data->hm_component < 1
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->line--;
		put_player(map);
	}
	map->score++;
	print_score(map);
}

void	move_right_bonus(t_map *map)
{
	if (map->map[map->col][map->line + 1] == '1')
		return ;
	else
	{
		map->player_data.x += 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components_bonus(map);
		put_exit_or_floor(map);
		if (map->component_data->hm_component < 1
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->line++;
		put_player(map);
	}
	map->score++;
	print_score(map);
}

int	key_hook_bonus(int key, void *mlx)
{
	t_map	*map;

	map = mlx;
	if (key == 41)
		mlx_loop_end(map->mlx_data.mlx);
	if (key == 26 || key == 82)
		move_up_bonus(map);
	if (key == 22 || key == 81)
		move_down_bonus(map);
	if (key == 4 || key == 80)
		move_left_bonus(map);
	if (key == 7 || key == 79)
		move_right_bonus(map);
	if (key == 19)
		change_pov(map);
	return (0);
}
