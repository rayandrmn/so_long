# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayderha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 15:33:07 by rayderha          #+#    #+#              #
#    Updated: 2024/06/15 15:01:55 by rayderha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	clang

FLAG		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

#MLX_FLAG	=	-lX11 -lXext

#MLX_PATH	=	./minilibx-linux/

#MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

#MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	so_long.c ft_error.c check_map.c	 			\

SRC_DIR		=	./core/

#INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

#mlx:
#	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
#	@make -sC $(MLX_PATH)
#	@echo "\033[1;32mMLX_lib created\n"

$(NAME): lib  $(OBJ) #rajouter mlx
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME) # rajouter $(MLX_EX)
	@echo "\033[1;32m./so_long created\n"

clean:
	#@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	#@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re
