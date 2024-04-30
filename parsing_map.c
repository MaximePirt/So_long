/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:21:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/30 20:50:53 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *file)
{
	int		i;
	char	str[4];

	if (!file)
		return (-1);
	str[0] = '.';
	str[1] = 'b';
	str[2] = 'e';
	str[3] = 'r';
	i = 0;
	while (file[i])
		i++;
	if (i <= 4)
		return (-1);
	i = ft_strncmp_end(file, str, 4);
	if (i == -1)
		return (-1);
	return (0);
}

static int	how_many_line(char *file)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_func(fd, NULL, NULL, NULL);
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

void	oh_problems(t_map *map, char *str, int i)
{
	if ((i == map->size_y && ft_strlen(str) != map->line_len - 1) || (i > 1
			&& i != map->size_y && ft_strlen(str) != map->line_len)
		|| str[0] != '1' || str[map->line_len - 2] != '1')
		exit_func(map->fd, NULL, str, NULL);
}

void	check_size(t_map *map)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		exit_func(fd, map, NULL, NULL);
	str = get_next_line(fd);
	if (!str)
		exit_func(fd, map, NULL, NULL);
	map->line_len = ft_strlen(str);
	map->size_x = map->line_len;
	map->size_y = how_many_line(map->file_name);
	while (str && str[0] != 0)
	{
		i++;
		oh_problems(map, str, i);
		if (ft_check(str, '\0'))
			break ;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return ;
}
