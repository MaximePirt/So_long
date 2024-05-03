/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:33:00 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/03 21:26:05 by mpierrot         ###   ########.fr       */
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

int	ft_check_only(char *res, char c)
{
	int	i;
	int	a;

	a = ft_strlen(res);
	i = 0;
	if (!a)
		return (-1);
	while (i < a)
	{
		if (res[i] != c && res[i] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_only_string(char *res, char *c)
{
	int		i;
	int		j;
	size_t	check;

	check = 0;
	j = 0;
	i = 0;
	while (res[i])
	{
		while (c[j])
		{
			if (res[i] == c[j])
				check++;
			j++;
		}
		if (check == 0)
			return (-1);
		check = 0;
		j = 0;
		i++;
	}
	return (1);
}
