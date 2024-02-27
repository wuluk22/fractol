/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:40:00 by clegros           #+#    #+#             */
/*   Updated: 2024/02/27 11:08:30 by clegros          ###   ########.fr       */
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
	(void)fractal;
	if (keycode == ESC)
		close_event(fractal);
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
