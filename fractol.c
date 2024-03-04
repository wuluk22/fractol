/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:01 by clegros           #+#    #+#             */
/*   Updated: 2024/02/27 11:07:01 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("memory failure");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->esc_val = 4;
	fractal->iter_def = 42; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, ON_MOUSE_DW, 0, mouse_handle, fractal);
	mlx_key_hook(fractal->win, handle_keys, fractal);
	mlx_hook(fractal->win, ON_DESTROY, 0, (void *)close_event, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (fractal->win == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img, 
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
			{
				ft_putstr_fd(("Invalid input for Julia set\n"), STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd((ERROR_MESSAGE MANDELBROT " or " JULIA), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
