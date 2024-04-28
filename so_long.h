/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:50 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/28 06:39:52 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////
# include "stdio.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct s_map
{
	int				col;
	int				line;
	int				size_x;
	int				size_y;
	int				components;
	int				player;
	int				exit;
	char			**tab;
	struct s_map	*next;

	/* data */
}					t_map;

/////////// Parsing utils ///////////
int					check_name(char *file);
int					check_size(char *file);
// fill_w_water
int					preptoflood(char *str);
// int					flood_fill(char **tab, t_map *map, char fill);
void				flood_fill(t_map *map, int x, int y);

// exit
void				exit_func(int fd, t_map *lst, char *str, char **tab);
#endif