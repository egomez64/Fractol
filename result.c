/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:24:49 by egomez            #+#    #+#             */
/*   Updated: 2024/04/11 12:24:52 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_fractal(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "Mandelbrot", 11) == 0)
	{
		fractal->render_func = mandelbrot;
		result(fractal, fractal->render_func);
	}
	else if (ft_strncmp(fractal->name, "Julia", 5) == 0)
	{
		fractal->render_func = julia;
		result(fractal, fractal->render_func);
	}
}

int	num_rep(t_fractal *fractal)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < fractal->max && sqrt(fractal->zr * fractal->zr
			+ fractal->zi * fractal->zi) < 2)
	{
		tmp = fractal->zr;
		fractal->zr = fractal->zr * fractal->zr
			- fractal->zi * fractal->zi + fractal->cr;
		fractal->zi = tmp * fractal->zi * 2 + fractal->ci;
		i++;
	}
	if (i == fractal->max)
		return (0);
	return (i);
}

void	draw(t_fractal fractal, int repeat, double x, double y)
{
	if (repeat > 0)
		mlx_set_image_pixel(fractal.mlx, fractal.img, x, y, get_color(repeat));
	else
		mlx_set_image_pixel(fractal.mlx, fractal.img, x, y, 0x000000);
}

void	result(t_fractal *fractal, void (*fract)())
{
	double	x;
	double	y;
	int		repeat;

	x = 0;
	while (x <= SIZE1)
	{
		y = 0;
		while (y <= SIZE2)
		{
			fract(fractal, x, y);
			repeat = num_rep(fractal);
			draw(*fractal, repeat, x, y);
			y++;
		}
		x++;
	}
}
