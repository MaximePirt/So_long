/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:28:27 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/03 22:24:54 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_score(t_map *map)
{
	map->print_score = ft_strjoin("Score : ", ft_itoa(map->score));
	mlx_clear_window(map->mlx_data.mlx, map->mlx_data.win);
	image_in_wdw_bonus(map);
	mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
		map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
		* map->mlx_data.img_h);
	mlx_string_put(map->mlx_data.mlx, map->mlx_data.win, 12, 12, 0xFFFFFFFF,
		map->print_score);
}
