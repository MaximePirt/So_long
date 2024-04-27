/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:53:13 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/26 21:25:59 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*invert_str(char *s2)
{
	size_t	i;
	size_t	j;
	size_t	z;
	char	switch_char;

	i = 0;
	j = 0;
	while (s2[i])
		i++;
	i--;
	z = i;
	while (i > z / 2)
	{
		switch_char = s2[i];
		s2[i] = s2[j];
		s2[j] = switch_char;
		i--;
		j++;
	}
	return (s2);
}

int	ft_strncmp_end(const char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str_rev;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	str_rev = invert_str(s2);
	i--;
	j++;
	while ((j < n) && (s2[i] || i > 0))
	{
		if (s2[j] && s1[i] && s1[i] != s2[j])
			return (-1);
		i--;
		j++;
	}
	return (0);
}
