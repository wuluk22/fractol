# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegros <clegros@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:03:58 by clegros           #+#    #+#              #
#    Updated: 2024/03/04 11:04:00 by clegros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
OBJ     = $(SRC:.c=.o)
BONUS_O	= $(BONUS:.c=.o)
NAMELIB = libftfractol.a
MLX_DIR	= minilibx_opengl_20191021
LINK    = -lmlx -framework OpenGL -framework AppKit -L $(MLX_DIR)
SRC     = fractol.c render.c events.c math_utils.c string_utils.c
BONUS	= fractol.c render.c events_bonus.c math_utils.c string_utils.c
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
COMP    = $(CC) $(CFLAGS) $(LINK) -fsanitize=address
RM      = rm -f

all:	$(NAME)

$(NAME): $(OBJ) fractol.h libmlx
	$(COMP) $(OBJ) -o $(NAME) -L. -lmlx

bonus:	$(BONUS_O) fractol.h libmlx
	$(COMP) $(BONUS_O) -o $(NAME) -L. -lmlx

libmlx:
	@make -C $(MLX_DIR)

clean:
	$(RM) $(OBJ) $(BONUS_O)
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAMELIB)
	@make -C $(MLX_DIR) clean

re:     fclean all
