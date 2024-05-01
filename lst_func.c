/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:34:56 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/01 04:35:12 by mpierrot         ###   ########.fr       */
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
	map->i = 0;
	map->score = 0;
	map->component_data = ft_calloc(1, sizeof(t_components));
	if (!map->component_data)
		exit_func(0, map, NULL, NULL);
	map->component_data->lst_component = ft_calloc(1, sizeof(t_componentlst));
	if (!map->component_data)
		exit_func(0, map, NULL, NULL);
	map->component_data->lst_component->next = NULL;
	map->component_data->hm_component = 0;
	map->component_data->lst_component->is_loot = 0;
	map->player_data.player = 0;
	map->exit_data.exit = 0;
	return (map);
}

void	ft_lstadd_front_cmpnt(t_componentlst **lst, t_componentlst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_cmpnt(t_componentlst **lst, t_componentlst *new)
{
	t_componentlst	*tmp;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		tmp = ft_datalstlast_cmpnt(*lst);
		tmp->next = new;
	}
	else
		ft_lstadd_front_cmpnt(lst, new);
}

t_componentlst	*ft_datalstlast_cmpnt(t_componentlst *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
t_componentlst	*ft_lstnew_cmpnt(t_componentlst *content, int x, int y)
{
	t_componentlst	*new;

	new = 0;
	new = ft_calloc(1, sizeof(t_componentlst));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->is_loot = 0;
	new->next = NULL;
	(void)content;
	return (new);
}

void	ft_t_compolstclear(t_componentlst *lst)
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
