/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:16:52 by clegros           #+#    #+#             */
/*   Updated: 2024/02/24 13:21:38 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define MANDELBROT "\033[32;4m./fractol mandelbrot\e[0m"
# define JULIA "\033[32;4m./fractol julia <value_1> <value_2>\e[0m\n\n"
# define ERROR_MESSAGE "\n\033[30;101m Please enter : \e[0m\n\n\t"
# define WIDTH   800
# define HEIGHT  800

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

enum
{
	ESC			= 53,
	ON_DESTROY	= 17,
	ON_MOUSE_DW	= 4,
};

typedef struct s_complex
{
	double		x;
	double		y;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*name;
	double	esc_val;
	int		iter_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		atodbl(char *s);

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

void		events_init(t_fractal *fractal);
int			handle_keys(int keycode, t_fractal *fractal);
int			mouse_handle(int mousecode, int x, int y, t_fractal *fractal);
int			close_event(t_fractal *fractal);

double		map(double unsc_num, double n_min, double n_max, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
