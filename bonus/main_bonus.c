/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:32:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 04:42:01 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_components_bonus(t_map *map)
{
	t_componentlst	*tmp;

	tmp = map->component_data->lst_component;
	while (tmp)
	{
		if (tmp->x == map->player_data.y && tmp->y == map->player_data.x
			&& tmp->is_loot == 0)
		{
			tmp->is_loot = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp && tmp->is_loot == 1)
		map->component_data->hm_component--;
	map->map[map->player_data.y][map->player_data.x] = '0';
}

int	window_hook_bonus(int event, void *param)
{
	t_map	*map;

	map = param;
	if (event == 0)
		mlx_loop_end(map->mlx_data.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || check_name_bonus(argv[1]) == -1)
		exit_func_bonus(0, NULL, NULL, 1);
	map = preptoflood_bonus(argv[1]);
	map->mlx_data.mlx = mlx_init();
	if (!map->mlx_data.mlx)
		exit_func_bonus(0, map, NULL, 6);
	map->mlx_data.win = mlx_new_window(map->mlx_data.mlx, WIDTH * (map->size_x
				- 1), HEIGHT * map->size_y, "So_long");
	if (!map->mlx_data.win)
		exit_func_bonus(0, map, NULL, 6);
	init_img_bonus_p(map);
	init_img_bonus(map);
	image_in_wdw_bonus(map);
	map->map[map->player_data.y][map->player_data.x] = '0';
	mlx_on_event(map->mlx_data.mlx, map->mlx_data.win, MLX_KEYDOWN,
		key_hook_bonus, map);
	mlx_on_event(map->mlx_data.mlx, map->mlx_data.win, MLX_WINDOW_EVENT,
		window_hook_bonus, map);
	// mlx_string_put(map->mlx_data.mlx, map->mlx_data.win, 12, 12, 0xFFFFFFFF,
	// 	"score");
	mlx_loop(map->mlx_data.mlx);
	destroy_bonus(map, 2);
	return (0);
}
