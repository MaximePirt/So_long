/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_w_water_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:19:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/03 22:15:28 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	copy_map_to_mapfill_bonus(t_map *map)
{
	size_t	i;

	map->map_fill = ft_calloc(sizeof(char *), (map->size_y + 1));
	if (!map->map_fill)
		exit_func_bonus(0, map, NULL);
	i = 0;
	while (map->map[i])
	{
		map->map_fill[i] = ft_strdup(map->map[i]);
		map->map_fill[i][map->size_x - 1] = '\0';
		i++;
	}
	return ;
}

void	clean_flood_bonus(t_map *map)
{
	t_componentlst	*tmp;

	free_tab(map->map_fill);
	tmp = map->component_data->lst_component;
	map->component_data->lst_component = map->component_data->lst_component->next;
	free(tmp);
	map->map_fill = NULL;
	tmp = NULL;
}

int	hm_compo_bonus(char **tab)
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
				exit_func_bonus(0, NULL, tab);
			if (tab[a][i] == 'C' || tab[a][i] == 'E' || tab[a][i] == 'P')
				compo++;
			i++;
		}
		i = 0;
		a++;
	}
	return (compo);
}
