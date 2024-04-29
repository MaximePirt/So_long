/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:21:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/28 20:21:42 by mpierrot         ###   ########.fr       */
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

void	oh_problems(size_t size, int that_much, char *str, t_map *test)
{
	if ((test->i == that_much && ft_strlen(str) != size - 1) || (test->i > 1
			&& test->i != that_much && ft_strlen(str) != size) || str[0] != '1'
		|| str[size - 2] != '1')
		exit_func(test->fd, NULL, str, NULL);
}

int	check_size(char *file)
{
	char	*str;
	size_t	size;
	int		that_much;
	t_map	test;

	test.i = 0;
	test.fd = open(file, O_RDONLY);
	if (test.fd == -1)
		exit_func(test.fd, NULL, NULL, NULL);
	str = get_next_line(test.fd);
	size = ft_strlen(str);
	that_much = how_many_line(file);
	while (str && str[0] != 0)
	{
		test.i++;
		oh_problems(size, that_much, str, &test);
		if (ft_check(str, '\0'))
			break ;
		free(str);
		str = get_next_line(test.fd);
	}
	free(str);
	close(test.fd);
	return (test.i);
}
