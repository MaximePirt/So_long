/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:46 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/27 03:34:37 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// External Libs
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

// main file
char	*ft_readline(int fd, char *res, char *tamp);
int		ft_result_sort(char **res, char **tamp);
char	*get_next_line(int fd);

// GNL utils

char	*lastfill(char *buff, char *tamp);

#endif