/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:32:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/30 09:45:22 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_t_map(char *str)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_func(0, NULL, NULL, NULL);
	map->file_name = str;
	map->col = 0;
	map->line = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->component_data = ft_calloc(1, sizeof(t_component));
	if (!map->component_data)
		exit_func(0, map, NULL, NULL);
	map->component_data->hm_component = 0;
	map->player_data.player = 0;
	map->exit_data.exit = 0;
	return (map);
}

void	init_img(t_map *map)
{
	map->mlx_data.img_floor = mlx_png_file_to_image(map->mlx_data.mlx,
			"textures/floor.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.img_wall = mlx_png_file_to_image(map->mlx_data.mlx,
			"textures/wall.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.p_sprite = mlx_png_file_to_image(map->mlx_data.mlx,
			"sprites/player.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.img_compo = mlx_png_file_to_image(map->mlx_data.mlx,
			"textures/cons.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	map->mlx_data.img_exit = mlx_png_file_to_image(map->mlx_data.mlx,
			"sprites/exit.png", &map->mlx_data.img_w, &map->mlx_data.img_h);
	if (!map->mlx_data.img_floor || !map->mlx_data.img_wall
		|| !map->mlx_data.img_exit || !map->mlx_data.p_sprite
		|| !map->mlx_data.img_compo)
		exit_func(0, map, NULL, NULL);
}

void	forest(t_map *map, int i, int j)
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
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
	else if (map->map[j][i] == 'E')
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.img_exit, i * map->mlx_data.img_w, j
			* map->mlx_data.img_h);
}
void	image_in_wdw(t_map *map)
{
	int	i;
	int	j;

	init_img(map);
	i = 0;
	j = 0;
	while (map->map[j])
	{
		while (map->map[j][i] && map->map[j][i] != '\n')
		{
			forest(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || check_name(argv[1]) == -1)
		exit_func(0, NULL, NULL, NULL);
	map = preptoflood(argv[1]);
	map->mlx_data.mlx = mlx_init();
	if (!map->mlx_data.mlx)
		exit_func(0, map, NULL, NULL);
	map->mlx_data.win = mlx_new_window(map->mlx_data.mlx, WIDTH * (map->size_x
				- 1), HEIGHT * map->size_y, "So_long");
	if (!map->mlx_data.win)
		exit_func(0, map, NULL, NULL);
	image_in_wdw(map);
	mlx_loop(map->mlx_data.mlx);
	/// destroy
	mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_floor);
	mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_wall);
	mlx_destroy_window(map->mlx_data.mlx, map->mlx_data.win);
	mlx_destroy_display(map->mlx_data.mlx);
	free_tab(map->map);
	free(map->component_data);
	free(map);
	return (0);
}

void	exit_func(int fd, t_map *lst, char *str, char **tab)
{
	ft_putstr_fd("Error\n", 2);
	(void)fd;
	if (fd)
		close(fd);
	if (lst)
	{
		free_tab(lst->map);
		if (lst->map_fill)
			free_tab(lst->map_fill);
		free(lst);
		lst = NULL;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (tab)
	{
		free_tab(tab);
		tab = NULL;
	}
	exit(EXIT_FAILURE);
}
