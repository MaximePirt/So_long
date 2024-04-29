# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:03:26 by mpierrot          #+#    #+#              #
#    Updated: 2024/04/28 23:56:30 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F	= main.c parsing_map.c fill_w_water.c

SRC_D	= srcs/
OBJ_D = objs

OBJ_F = $(SRC_F:%.c=$(OBJ_D)/%.o)
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
CLIBS = -g -Wall -Wextra -Werror -lSDL2
RM = rm -rf
AR = ar rcs
NAME = so_long
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLXDIR = MacroLibX
MLX = $(MLXDIR)/libmlx.so
INCLUDES = -I includes/ -I $(LIBFT_DIR)/includes/ 
INCLUDES2 = -I includes/ -I $(MLXDIR)/includes/

DEFCOLOR	= \033[0;39m
CYAN		= \033[1;96m
PURPLE		= \033[0;95m
YELLOW		= \033[0;93m
RED			= \033[0;91m




all: $(NAME)

$(LIBFT):
	@$(MAKE) -s -j -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -s -j -C $(MLXDIR)

$(NAME): $(OBJ_F) $(LIBFT) $(MLX)
	@$(CC) $(OBJ_F) $(MLX) $(LIBFT) -o $(NAME) $(CLIBS) $(INCLUDES) $(INCLUDES2)
	@echo "$(CYAN)So_long has been compiled successfully$(DEFCOLOR)"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	@echo "$(YELLOW)Compiling $<$(DEFCOLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLXDIR) clean
	@$(RM) objs 
	@echo "$(PURPLE)So_long object files cleaned !!$(DEFCOLOR)"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLXDIR) fclean

	@$(RM) $(NAME)
	@echo "$(RED)So_long executable has been destroy$(DEFCOLOR)"

re: fclean all

.PHONY: all clean fclean re