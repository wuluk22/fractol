/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:39:56 by clegros           #+#    #+#             */
/*   Updated: 2024/03/04 12:40:01 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_event(t_fractal *fractal)
{
	(void)fractal;
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keys(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		close_event(fractal);
	if (keycode == LEFT_ARROW)
		fractal->shift_x -= (0.1 * fractal->zoom);
	else if (keycode == RIGHT_ARROW)
		fractal->shift_x += (0.1 * fractal->zoom);
	else if (keycode == UP_ARROW)
		fractal->shift_y += (0.1 * fractal->zoom);
	else if (keycode == DOWN_ARROW)
		fractal->shift_y -= (0.1 * fractal->zoom);
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		fractal->zoom *= 1.05;
	if (mousecode == 5)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
	return (0);
}
