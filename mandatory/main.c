/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:32:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 04:43:44 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_components(t_map *map)
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
}

int	window_hook(int event, void *param)
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

	if (argc != 2 || check_name(argv[1]) == -1)
		exit_func(0, NULL, NULL, 1);
	map = preptoflood(argv[1]);
	map->mlx_data.mlx = mlx_init();
	if (!map->mlx_data.mlx)
		exit_func(0, map, NULL, 6);
	map->mlx_data.win = mlx_new_window(map->mlx_data.mlx, WIDTH * (map->size_x
				- 1), HEIGHT * map->size_y, "So_long");
	if (!map->mlx_data.win)
		exit_func(0, map, NULL, 6);
	image_in_wdw(map);
	mlx_on_event(map->mlx_data.mlx, map->mlx_data.win, MLX_KEYDOWN, key_hook,
		map);
	mlx_on_event(map->mlx_data.mlx, map->mlx_data.win, MLX_WINDOW_EVENT,
		window_hook, map);
	mlx_loop(map->mlx_data.mlx);
	destroy(map, 2);
	return (0);
}
