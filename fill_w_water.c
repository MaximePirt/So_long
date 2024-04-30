/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_w_water.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:41 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/30 09:25:44 by mpierrot         ###   ########.fr       */
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

void	flood_fill(t_map *map, int x, int y)
{
	if (!map->map_fill[x][y] || x < 0 || x >= map->size_y || y < 0
		|| y >= map->size_x || map->map_fill[x][y] == '1'
		|| map->map_fill[x][y] == 'F')
		return ;
	if (map->map_fill[x][y] == 'C')
		map->component_data->hm_component++;
	else if (map->map_fill[x][y] == 'P')
		map->player_data.player++;
	else if (map->map_fill[x][y] == 'E')
		map->exit_data.exit++;
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

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		fprintf(stderr, "%s\n", map->map[i]);
		i++;
	}
	write(2, "\n", 1);
	write(2, "\n", 1);
	write(2, "\n", 1);
	i = 0;
	while (map->map_fill[i])
	{
		fprintf(stderr, "%s\n", map->map_fill[i]);
		i++;
	}
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
	////////////////
	print_map(map);
	///////////////
	map->component_data->hm_component += map->player_data.player
		+ map->exit_data.exit;
	if (component != map->component_data->hm_component
		|| map->component_data->hm_component < 3)
		exit_func(0, map, NULL, NULL);
	free_tab(map->map_fill);
	return (map);
}
