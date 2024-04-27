/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:33:00 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/27 04:26:50 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_check(char *res, char c)
{
	int	i;
	int	a;

	a = ft_strlen(res);
	i = 0;
	if (!a)
		return (0);
	while (i != a)
	{
		if (res[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checknop(char *res, char c)
{
	int	i;
	int	a;

	a = ft_strlen(res);
	i = 0;
	if (!a)
		return (0);
	while (i != a)
	{
		if (res[i] == c)
			return (-1);
		i++;
	}
	return (1);
}
