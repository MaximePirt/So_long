/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:34:56 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/02 01:26:51 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
