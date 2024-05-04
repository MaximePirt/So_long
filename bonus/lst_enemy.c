/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:18:02 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/04 09:26:29 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_lstadd_front_enemy(t_enemy **lst, t_enemy *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_enemy(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		tmp = ft_datalstlast_enemy(*lst);
		tmp->next = new;
	}
	else
		ft_lstadd_front_enemy(lst, new);
}

t_enemy	*ft_datalstlast_enemy(t_enemy *lst)
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

t_enemy	*ft_lstnew_enemy(t_enemy *content, int x, int y)
{
	t_enemy *new;

	new = 0;
	new = ft_calloc(1, sizeof(t_enemy));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->life = 100;
	new->dead = 0;
	/// manque le type
	new->next = NULL;
	(void)content;
	return (new);
}