/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:18:37 by clegros           #+#    #+#             */
/*   Updated: 2024/02/28 10:18:39 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0') && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	valid_init(t_double *vld)
{
	vld->dots = 0;
	vld->digits = 0;
	vld->i = 0;
}

bool	is_valid_double(const char *str)
{
	t_double	vld;

	valid_init(&vld);
	while (str[vld.i] != '\0')
	{
		if ((str[vld.i] >= '0' && str[vld.i] <= '9') || (str[vld.i] == '.')
			|| (vld.i == 0 && str[vld.i] == '-'))
		{
			if (str[vld.i] == '.')
			{
				if (vld.dots > 0)
					return (false);
				vld.dots++;
			}
			else
				vld.digits++;
		}
		else
			return (false);
		vld.i++;
	}
	if (vld.digits == 0)
		return (false);
	return (true);
}
