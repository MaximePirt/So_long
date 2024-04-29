/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_w_water.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:41 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/29 03:31:40 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	filltab(char *file, t_map *map)
{
	char	*line;
	int		map_size;
	int		i;
	int		fd;

	i = 0;
	map_size = check_size(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_func(fd, map, NULL, map->tab);
	line = get_next_line(fd);
	map->tab = malloc(sizeof(char *) * (map_size + 1));
	map_size = ft_strlen(line);
	while (line)
	{
		map->tab[i] = ft_strdup(line);
		map->tab[i][map_size - 1] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->tab[i] = NULL;
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
	if (x < 0 || x >= map->size_x || y < 0 || y >= map->size_y
		|| map->tab[x][y] == '1' || map->tab[x][y] == 'F')
		return ;
	if (map->tab[x][y] == 'C')
		map->components++;
	else if (map->tab[x][y] == 'P')
		map->player++;
	else if (map->tab[x][y] == 'E')
		map->exit++;
	map->tab[x][y] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	if (map->player > 1 || map->exit > 1)
		exit_func(0, map, NULL, NULL);
	return ;
}

static void	where_start_fill(t_map *map)
{
	while (map->col < map->size_x && map->col < map->size_y
		&& (map->tab[map->col][map->line]
			&& map->tab[map->col][map->line] != 'P'))
	{
		while (map->col < map->size_x && map->col < map->size_y
			&& (map->tab[map->col][map->line]
				&& map->tab[map->col][map->line] != 'P'))
			map->line++;
		if (map->tab[map->col][map->line]
			&& map->tab[map->col][map->line] == 'P')
			return ;
		map->line = 0;
		map->col++;
	}
}

t_map	*preptoflood(char *str)
{
	int		i;
	int		component;
	t_map	*map;

	i = 0;
	map = ft_calloc(2, sizeof(t_map));
	if (!map)
		exit_func(0, NULL, NULL, NULL);
	filltab(str, map);
	init_t_map(map, str);
	component = hm_compo(map->tab);
	where_start_fill(map);
	if (map->tab[map->col][map->line] && map->tab[map->col][map->line] != '\n')
		flood_fill(map, map->col, map->line);
	else
		exit_func(0, map, NULL, NULL);
	map->components += map->player + map->exit;
	if (component != map->components || map->components < 3)
		exit_func(0, map, NULL, NULL);
	else
		printf("YOUHOU VASY MAHKU JTE SUCE MERCI");
	filltab(str, map);
	return (map);
}
