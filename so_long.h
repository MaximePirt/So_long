/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:50 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/27 07:40:46 by mpierrot         ###   ########.fr       */
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

/////////// Parsing utils ///////////
int		check_name(char *file);
int		check_size(char *file);
// fill_w_water
int		preptoflood(char *str);
int		floodfill(char ***tab, int count, int a, int i);

// exit
void	exit_func(int fd, char *str, char *str2, char **tab);

#endif