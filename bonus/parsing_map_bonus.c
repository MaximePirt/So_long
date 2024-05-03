/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:21:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/03 22:15:47 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_name_bonus(char *file)
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

static int	how_many_line_bonus(char *file)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, NULL, NULL);
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
	free(str);
	str = NULL;
	close(fd);
	return (i);
}

void	oh_problems_bonus(t_map *map, char *str, int i, int fd)
{
	if ((i == map->size_y && ft_strlen(str) != map->line_len - 1) || (i > 1
			&& i != map->size_y && ft_strlen(str) != map->line_len)
		|| str[0] != '1' || str[map->line_len - 2] != '1' || (i == map->size_y
			&& ft_check_only(str, '1') == -1) || (i == 1 && ft_check_only(str,
				'1') == -1) || map->size_y < 3 || ((i > 1 && i != map->size_y)
			&& ft_check_only_string(str, "10ECP\n") == -1))
	{
		free(str);
		str = NULL;
		exit_func_bonus(fd, map, NULL);
	}
}

void	check_size_bonus(t_map *map)
{
	char	*str;
	int		fd;
	int		i;

	i = 1;
	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		exit_func_bonus(0, map, NULL);
	str = get_next_line(fd);
	if (!str)
		exit_func_bonus(fd, map, NULL);
	map->line_len = ft_strlen(str);
	map->size_x = map->line_len;
	map->size_y = how_many_line_bonus(map->file_name);
	while (str && str[0] != 0)
	{
		oh_problems_bonus(map, str, i++, fd);
		if (ft_check(str, '\0'))
			break ;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return ;
}
