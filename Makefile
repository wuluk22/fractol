NAME    = fractol
OBJ     = $(SRC:.c=.o)
NAMELIB = libftfractol.a
LINK    = -lmlx -framework OpenGL -framework AppKit -L minilibx_opengl_20191021
SRC     = fractol.c render.c events.c math_utils.c ft_atodbl.c ft_putstr_fd.c ft_strncmp.c ft_putendl_fd.c ft_memcpy.c
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
COMP    = $(CC) $(CFLAGS) $(LINK) -fsanitize=address
RM      = rm -f

all:	$(NAME)

$(NAME): $(OBJ) fractol.h
	$(COMP) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) fractol

re:     fclean all
