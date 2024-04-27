/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_w_water.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:41 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/27 08:07:25 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_items(char **map)
{
	(void)map;
	return (0);
}

char	**filltab(char *file)
{
	char	**tab;
	char	*line;
	int		map_size;
	int		i;
	int		fd;

	i = 0;
	map_size = check_size(file);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	tab = malloc(sizeof(char *) * (map_size + 1));
	map_size = ft_strlen(line);
	while (line)
	{
		tab[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	tab[i] = NULL;
	free(line);
	close(fd);
	return (tab);
}
//  Retirer le '\n' a la fin de chaque ligne

int	hm_compo(char **tab)
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
			{
				printf("vla la string [%s]", tab[a]);
				exit_func(0, NULL, NULL, tab);
			}
			if (tab[a][i] == 'C' || tab[a][i] == 'E' || tab[a][i] == 'P')
				compo++;
			i++;
		}
		i = 0;
		a++;
	}
	return (compo);
}

int	floodfill(char ***tab, int count, int a, int i)
{
	if (*tab[a][i] == 'C' || *tab[a][i] == 'E' || *tab[a][i] == 'P')
	{
		count += 1;
		*tab[a][i] = 'F';
	}
	if (*tab[a][i] == '0')
	{
		*tab[a][i] = 'F';
		if (*tab[a][(i + 1)] && *tab[a][(i + 1)] != 'F')
			count += floodfill(tab, count, a, i++);
		else if (tab[(a + 1)][i] && *tab[(a + 1)][i] != 'F')
			count += floodfill(tab, count, a++, i);
		else if (tab[a][(i--)] && *tab[a][(i--)] != 'F')
			count += floodfill(tab, count, a, i--);
		else if (tab[a--][i] && *tab[a--][i] != 'F')
			count += floodfill(tab, count, a--, i);
		else
		{
			printf("vla count dans else[%d]\n", count);
			return (count);
		}
	}
	printf("vla count [%d]\n", count);
	return (count);
}

int	preptoflood(char *str)
{
	char	**tab;
	int		i;
	int		component;
	int		fill_component;

	i = 0;
	tab = filltab(str);
	component = hm_compo(tab);
	// while (tab[i])
	// {
	// 	printf("tab[i] [%s]", tab[i]);
	// 	i++;
	// }
	fill_component = floodfill(&tab, 0, 1, 1);
	printf("vla fill [%d]", fill_component);
	if (fill_component != component)
		exit_func(0, NULL, NULL, tab);
	free_tab(tab);
	return (0);
}
