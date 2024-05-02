/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_w_water_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:41 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/02 07:10:47 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	filltab_bonus(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	line = get_next_line(fd);
	map->size_x = ft_strlen(line);
	i = 0;
	while (line)
	{
		map->map[i] = ft_strdup(line);
		map->map[i][map->size_x - 1] = '\0';
		free(line);
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
	}
	free(line);
	close(fd);
	return ;
}

void	fill_struc_compo_bonus(t_map *map, char c, int x, int y)
{
	if (c == 'C')
	{
		map->component_data->hm_component++;
		ft_lstadd_back_cmpnt_bonus(&map->component_data->lst_component,
			ft_lstnew_cmpnt_bonus(map->component_data->lst_component, x, y));
	}
	else if (c == 'P')
	{
		map->player_data.player++;
		map->player_data.x = y;
		map->player_data.y = x;
	}
	else if (c == 'E')
	{
		map->exit_data.exit++;
		map->exit_data.x = x;
		map->exit_data.x = y;
	}
	return ;
}

void	flood_fill_bonus(t_map *map, int x, int y)
{
	if (!map->map_fill[x][y] || x < 0 || x >= map->size_y || y < 0
		|| y >= map->size_x || map->map_fill[x][y] == '1'
		|| map->map_fill[x][y] == 'F')
		return ;
	fill_struc_compo_bonus(map, map->map_fill[x][y], x, y);
	map->map_fill[x][y] = 'F';
	flood_fill_bonus(map, x - 1, y);
	flood_fill_bonus(map, x + 1, y);
	flood_fill_bonus(map, x, y - 1);
	flood_fill_bonus(map, x, y + 1);
	if (map->player_data.player > 1 || map->exit_data.exit > 1)
		exit_func_bonus(0, map, NULL);
	return ;
}

void	where_start_fill_bonus(t_map *map)
{
	while (map->col < map->size_y && map->col < map->size_x
		&& (map->map[map->col][map->line]
			&& map->map[map->col][map->line] != 'P'))
	{
		while (map->col < map->size_y && map->col < map->size_x
			&& (map->map[map->col][map->line]
				&& map->map[map->col][map->line] != 'P'))
			map->line++;
		if (map->map[map->col][map->line]
			&& map->map[map->col][map->line] == 'P')
			return ;
		map->line = 0;
		map->col++;
	}
}

t_map	*preptoflood_bonus(char *str)
{
	int		component;
	t_map	*map;
	int		i;

	i = 0;
	map = init_t_map_bonus(str);
	check_size_bonus(map);
	map->map = ft_calloc(sizeof(char *), (map->size_y + 1));
	if (!map->map)
		exit_func_bonus(0, map, NULL);
	filltab_bonus(map);
	copy_map_to_mapfill_bonus(map);
	component = hm_compo_bonus(map->map);
	where_start_fill_bonus(map);
	if (map->map[map->col][map->line] && map->map[map->col][map->line] != '\n')
		flood_fill_bonus(map, map->col, map->line);
	else
		exit_func_bonus(0, map, NULL);
	if (component != map->component_data->hm_component + map->player_data.player
		+ map->exit_data.exit || map->component_data->hm_component < 1)
		exit_func_bonus(0, map, NULL);
	clean_flood_bonus(map);
	return (map);
}
