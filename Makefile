# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:03:26 by mpierrot          #+#    #+#              #
#    Updated: 2024/05/02 04:53:58 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F	= 	mandatory/main.c mandatory/parsing_map.c mandatory/fill_w_water.c mandatory/lst_func.c  mandatory/mlx-img.c\
			mandatory/end.c mandatory/fill_w_water_utils.c mandatory/key_mvmt.c mandatory/lst_func_init_clear.c
			
SRC_FB = 	bonus/main_bonus.c bonus/parsing_map_bonus.c bonus/fill_w_water_bonus.c bonus/lst_func_bonus.c  bonus/mlx-img_bonus.c \
			bonus/end_bonus.c bonus/fill_w_water_utils_bonus.c bonus/key_mvmt_bonus.c bonus/lst_func_init_clear_bonus.c \
			utils_to_delet.c
			
SRC_D	= src/

OBJ_D = objs
OBJ_DB = objs_bonus


OBJ_F = $(SRC_F:%.c=$(OBJ_D)/%.o)
OBJ_FB = $(SRC_FB:%.c=$(OBJ_DB)/%.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
CLIBS = -g -Wall -Wextra -Werror -lSDL2
RM = rm -rf
AR = ar rcs
NAME = so_long
NAME_BONUS = so_long_bonus
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
	@$(CC) $(CFLAGS) $(OBJ_F) $(MLX) $(LIBFT) -o $(NAME) $(CLIBS) $(INCLUDES) $(INCLUDES2)
	@echo "$(CYAN)So_long has been compiled successfully$(DEFCOLOR)"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)/mandatory
	@echo "$(YELLOW)Compiling $<$(DEFCOLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DB)/%.o: %.c
	@mkdir -p $(OBJ_DB)/bonus
	@echo "$(YELLOW)Compiling $<$(DEFCOLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_FB) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ_FB) $(MLX) $(LIBFT) -o $(NAME_BONUS) $(CLIBS) $(INCLUDES) $(INCLUDES2)
	@echo "$(RED)So_long_bonus has been compiled successfully$(DEFCOLOR)"
	
clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLXDIR) clean
	@$(RM) objs objs_bonus
	@echo "$(PURPLE)So_long object files cleaned !!$(DEFCOLOR)"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLXDIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "$(RED)So_long executable has been destroy$(DEFCOLOR)"

re: fclean all

.PHONY: all clean fclean re bonus