/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:32:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/01 04:38:23 by mpierrot         ###   ########.fr       */
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

void	move_up(t_map *map)
{
	if (map->map[(map->col - 1)][map->line] == '1')
		return ;
	else
	{
		map->player_data.y -= 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y + 1][map->player_data.x] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->col--;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}

void	move_down(t_map *map)
{
	if (map->map[(map->col + 1)][map->line] == '1')
		return ;
	else
	{
		map->player_data.y += 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y - 1][map->player_data.x] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->col++;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}
void	move_left(t_map *map)
{
	if (map->map[map->col][map->line - 1] == '1')
		return ;
	else
	{
		map->player_data.x -= 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y][map->player_data.x + 1] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->line--;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}
void	move_right(t_map *map)
{
	if (map->map[map->col][map->line + 1] == '1')
		return ;
	else
	{
		map->player_data.x += 1;
		if (map->map[map->player_data.y][map->player_data.x] == 'C')
			check_components(map);
		if (map->map[map->player_data.y][map->player_data.x - 1] == 'E')
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_exit, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		else
			mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
				map->mlx_data.img_floor, map->line * map->mlx_data.img_w,
				map->col * map->mlx_data.img_h);
		if (map->component_data->hm_component < 3
			&& map->map[map->player_data.y][map->player_data.x] == 'E')
			mlx_loop_end(map->mlx_data.mlx);
		map->line++;
		mlx_put_image_to_window(map->mlx_data.mlx, map->mlx_data.win,
			map->mlx_data.p_sprite, map->line * map->mlx_data.img_w, map->col
			* map->mlx_data.img_h);
	}
	map->score++;
	ft_printf("%d\n", map->score);
}
int	key_hook(int key, void *mlx)
{
	t_map	*map;

	map = mlx;
	// init_img(map);
	if (key == 41)
		mlx_loop_end(map->mlx_data.mlx);
	if (key == 26 || key == 82)
		move_up(map);
	if (key == 22 || key == 81)
		move_down(map);
	if (key == 4 || key == 80)
		move_left(map);
	if (key == 7 || key == 79)
		move_right(map);
	if (key == 19)
		return (0);
	return (0);
}

int	window_hook(int event, void *param)
{
	t_map	*map;

	map = param;
	if (event == 0)
		mlx_loop_end(map->mlx_data.mlx);
	return (0);
}

void	destroy(t_map *map, int which)
{
	if (map->mlx_data.img_floor)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_floor);
	if (map->mlx_data.img_wall)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_wall);
	if (map->mlx_data.p_sprite)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.p_sprite);
	if (map->mlx_data.img_exit)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_exit);
	if (map->mlx_data.img_compo)
		mlx_destroy_image(map->mlx_data.mlx, map->mlx_data.img_compo);
	if (map->mlx_data.win)
		mlx_destroy_window(map->mlx_data.mlx, map->mlx_data.win);
	if (map->mlx_data.mlx)
		mlx_destroy_display(map->mlx_data.mlx);
	if (which == 2)
	{
		ft_t_compolstclear(map->component_data->lst_component);
		free(map->component_data);
		free_tab(map->map);
		free(map);
	}
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
	mlx_on_event(map->mlx_data.mlx, map->mlx_data.win, MLX_KEYDOWN, key_hook,
		map);
	mlx_on_event(map->mlx_data.mlx, map->mlx_data.win, MLX_WINDOW_EVENT,
		window_hook, map);
	mlx_string_put(map->mlx_data.mlx, map->mlx_data.win, 12, 12, 0xFFFFFFFF,
		"score");
	mlx_loop(map->mlx_data.mlx);
	//
	destroy(map, 2);
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
		if (lst->component_data->lst_component)
			ft_t_compolstclear(lst->component_data->lst_component);
		if (lst->component_data)
			free(lst->component_data);
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
