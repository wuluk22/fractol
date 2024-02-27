/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:14:43 by clegros           #+#    #+#             */
/*   Updated: 2024/02/22 14:34:35 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unsc_num, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (unsc_num) / (o_max) + n_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

t_complex	square_complex(t_complex z)
{
	t_complex	sqrt;

	sqrt.x = (z.x * z.x) - (z.y * z.y);
	sqrt.y = 2 * z.x * z.y;
	return (sqrt);
}
