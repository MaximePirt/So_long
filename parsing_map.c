/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:21:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/28 07:02:49 by mpierrot         ###   ########.fr       */
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

// int	checking_in_progress(char *str, size_t size, int fd, int i)
// {
// }
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

int	check_size(char *file)
{
	char	*str;
	int		fd;
	int		i;
	size_t	size;
	int		that_much;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_func(fd, NULL, NULL, NULL);
	str = get_next_line(fd);
	if (!str || str[0] != '1')
		exit_func(fd, NULL, NULL, NULL);
	size = ft_strlen(str);
	that_much = how_many_line(file);
	while (str && str[0] != 0)
	{
		i++;
		if ((i == that_much && ft_strlen(str) != size - 1) || (i > 1
				&& i != that_much && ft_strlen(str) != size) || str[0] != '1'
			|| str[size - 2] != '1')
			exit_func(fd, NULL, str, NULL);
		if (ft_check(str, '\0'))
			break ;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (check_name(argv[1]) == -1)
		return (-1);
	if (check_size(argv[1]) == -1)
	{
		printf("AH");
		return (-1);
	}
	if (preptoflood(argv[1]) == -1)
		return (-1);
	return (0);
}
