/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_delet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:26:29 by mpierrot          #+#    #+#             */
/*   Updated: 2024/05/02 04:50:36 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		fprintf(stderr, "%s\n", map->map[i]);
		i++;
	}
	write(2, "\n", 1);
	write(2, "\n", 1);
	write(2, "\n", 1);
	i = 0;
	while (map->map_fill[i])
	{
		fprintf(stderr, "%s\n", map->map_fill[i]);
		i++;
	}
}
