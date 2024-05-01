/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_w_water.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:41 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/01 02:54:45 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	filltab(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		exit_func(0, map, NULL, NULL);
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

static int	hm_compo(char **tab)
{
	int	i;
	int	a;
	int	compo;

	i = 0;
	a = 0;
	compo = 0;
	while (tab[a])
	{
		while (tab[a][i])
		{
			if (tab[a][i] != '1' && tab[a][i] != '0' && tab[a][i] != 'C'
				&& tab[a][i] != 'E' && tab[a][i] != 'P' && tab[a][i] != '\n')
				exit_func(0, NULL, NULL, tab);
			if (tab[a][i] == 'C' || tab[a][i] == 'E' || tab[a][i] == 'P')
				compo++;
			i++;
		}
		i = 0;
		a++;
	}
	return (compo);
}

void	fill_struc_compo(t_map *map, char c, int x, int y)
{
	if (c == 'C')
	{
		map->component_data->hm_component++;
		ft_lstadd_back_cmpnt(&map->component_data->lst_component,
			ft_lstnew_cmpnt(map->component_data->lst_component, x, y));
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

void	flood_fill(t_map *map, int x, int y)
{
	if (!map->map_fill[x][y] || x < 0 || x >= map->size_y || y < 0
		|| y >= map->size_x || map->map_fill[x][y] == '1'
		|| map->map_fill[x][y] == 'F')
		return ;
	fill_struc_compo(map, map->map_fill[x][y], x, y);
	map->map_fill[x][y] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	if (map->player_data.player > 1 || map->exit_data.exit > 1)
		exit_func(0, map, NULL, NULL);
	return ;
}

static void	where_start_fill(t_map *map)
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

void	copy_map_to_mapfill(t_map *map)
{
	size_t	i;

	map->map_fill = ft_calloc(sizeof(char *), (map->size_y + 1));
	if (!map->map_fill)
		exit_func(0, map, NULL, NULL);
	i = 0;
	while (map->map[i])
	{
		map->map_fill[i] = ft_strdup(map->map[i]);
		map->map_fill[i][map->size_x - 1] = '\0';
		i++;
	}
	return ;
}
void	clean_flood(t_map *map)
{
	t_componentlst	*tmp;

	free_tab(map->map_fill);
	tmp = map->component_data->lst_component;
	map->component_data->lst_component = map->component_data->lst_component->next;
	free(tmp);
}

t_map	*preptoflood(char *str)
{
	int		component;
	t_map	*map;
	int		i;

	i = 0;
	map = init_t_map(str);
	check_size(map);
	map->map = ft_calloc(sizeof(char *), (map->size_y + 1));
	if (!map->map)
		exit_func(0, map, NULL, NULL);
	filltab(map);
	copy_map_to_mapfill(map);
	component = hm_compo(map->map);
	where_start_fill(map);
	if (map->map[map->col][map->line] && map->map[map->col][map->line] != '\n')
		flood_fill(map, map->col, map->line);
	else
		exit_func(0, map, NULL, NULL);
	map->component_data->hm_component += map->player_data.player
		+ map->exit_data.exit;
	if (component != map->component_data->hm_component
		|| map->component_data->hm_component < 3)
		exit_func(0, map, NULL, NULL);
	clean_flood(map);
	return (map);
}
