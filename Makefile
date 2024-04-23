# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:03:26 by mpierrot          #+#    #+#              #
#    Updated: 2024/04/23 19:22:28 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F	= main.c parsing_map.c 

SRC_D	= srcs/
OBJ_D = objs

OBJ_F = $(SRC_F:%.c=$(OBJ_D)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
NAME = so_long
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I includes/ -I $(LIBFT_DIR)/includes/

DEFCOLOR	= \033[0;39m
CYAN		= \033[1;96m
PURPLE		= \033[0;95m
YELLOW		= \033[0;93m
RED			= \033[0;91m




all: $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(NAME): $(OBJ_F) $(LIBFT)
	@$(CC) $(OBJ_F) $(LIBFT) -o $(NAME) $(CFLAGS) $(INCLUDES)
	@echo "$(CYAN)So_long has been compiled successfully$(DEFCOLOR)"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	@echo "$(YELLOW)Compiling $<$(DEFCOLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(RM) objs 
	@echo "$(PURPLE)So_long object files cleaned !!$(DEFCOLOR)"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)So_long executable has been destroy$(DEFCOLOR)"

re: fclean all

.PHONY: all clean fclean re