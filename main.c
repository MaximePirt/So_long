/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:32:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/29 05:42:21 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_t_map(t_map *map, char *str)
{
	if (!map)
		exit_func(0, NULL, NULL, NULL);
	map->size_x = check_size(str);
	map->size_y = ft_strlen(map->tab[0]);
	map->col = 0;
	map->line = 0;
	map->components = 0;
	map->player = 0;
	map->exit = 0;
	return ;
}

void	init_img(t_map *map, void *mlx)
{
	map->img_floor = mlx_png_file_to_image(mlx, "textures/floor.png",
			&map->img_w, &map->img_h);
	map->img_h = 0;
	map->img_w = 0;
	map->img_wall = mlx_png_file_to_image(mlx, "textures/wall.png", &map->img_w,
			&map->img_h);
	map->img_h = 0;
	map->img_w = 0;
	map->p_sprite = mlx_png_file_to_image(mlx, "sprites/player.png",
			&map->img_w, &map->img_h);
	map->img_h = 0;
	map->img_w = 0;
	map->img_compo = mlx_png_file_to_image(mlx, "textures/cons.png",
			&map->img_w, &map->img_h);
	map->img_h = 0;
	map->img_w = 0;
	map->img_exit = mlx_png_file_to_image(mlx, "sprites/exit.png", &map->img_w,
			&map->img_h);
	if (!map->img_floor || !map->img_wall || !map->img_exit || !map->p_sprite
		|| !map->img_compo)
		exit_func(0, map, NULL, NULL);
	map->i = 0;
	map->j = 0;
}

void	forest(t_map *map, void *mlx)
{
	if (map->tab[map->j][map->i] == '1')
		mlx_put_image_to_window(mlx, map->win, map->img_wall, map->i
			* map->img_w, map->j * map->img_h);
	else if (map->tab[map->j][map->i] == '0')
		mlx_put_image_to_window(mlx, map->win, map->img_floor, map->i
			* map->img_w, map->j * map->img_h);
	else if (map->tab[map->j][map->i] == 'C')
		mlx_put_image_to_window(mlx, map->win, map->img_compo, map->i
			* map->img_w, map->j * map->img_h);
	else if (map->tab[map->j][map->i] == 'P')
		mlx_put_image_to_window(mlx, map->win, map->p_sprite, map->i
			* map->img_w, map->j * map->img_h);
	else if (map->tab[map->j][map->i] == 'E')
		mlx_put_image_to_window(mlx, map->win, map->img_exit, map->i
			* map->img_w, map->j * map->img_h);
}
void	image_in_wdw(void *mlx, t_map *map)
{
	init_img(map, mlx);
	while (map->tab[map->j])
	{
		while (map->tab[map->j][map->i] && map->tab[map->j][map->i] != '\n')
		{
			forest(map, mlx);
			map->i++;
		}
		map->i = 0;
		map->j++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_map	*map;
	void	*mlx;

	if (argc != 2)
		exit_func(0, NULL, NULL, NULL);
	if (check_name(argv[1]) == -1 || check_size(argv[1]) == -1)
		return (-1);
	map = preptoflood(argv[1]);
	printf("\n%d", map->size_y);
	mlx = mlx_init();
	if (!mlx)
		exit_func(0, map, NULL, NULL);
	map->win = mlx_new_window(mlx, HEIGHT * map->size_y, WIDTH * map->size_x,
			"So_long");
	if (!map->win)
		exit_func(0, map, NULL, NULL);
	image_in_wdw(mlx, map);
	mlx_loop(mlx);
	/// destroy
	mlx_destroy_image(mlx, map->img_floor);
	mlx_destroy_image(mlx, map->img_wall);
	mlx_destroy_window(mlx, map->win);
	mlx_destroy_display(mlx);
	free_tab(map->tab);
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
		free_tab(lst->tab);
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
