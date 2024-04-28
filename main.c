/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:32:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/28 06:39:46 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }

void	exit_func(int fd, t_map *lst, char *str, char **tab)
{
	printf("GROS YA SOUCIS");
	(void)fd;
	if (fd)
		close(fd);
	if (lst)
		free(str);
	if (str)
		free(str);
	if (tab)
		free_tab(tab);
	exit(EXIT_FAILURE);
}
