/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_init_clear_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:26:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/02 05:29:59 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*init_t_map_bonus(char *str)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_func_bonus(0, NULL, NULL);
	map->file_name = str;
	map->col = 0;
	map->line = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->i = 0;
	map->score = 0;
	map->component_data = ft_calloc(1, sizeof(t_components));
	if (!map->component_data)
		exit_func_bonus(0, map, NULL);
	map->component_data->lst_component = ft_calloc(1, sizeof(t_componentlst));
	if (!map->component_data)
		exit_func_bonus(0, map, NULL);
	map->component_data->lst_component->next = NULL;
	map->component_data->hm_component = 0;
	map->component_data->lst_component->is_loot = 0;
	map->player_data.player = 0;
	map->exit_data.exit = 0;
	return (map);
}

void	ft_t_compolstclear_bonus(t_componentlst *lst)
{
	t_componentlst	*tmp;
	t_componentlst	*next;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	lst = NULL;
}
