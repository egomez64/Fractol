/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:50:15 by egomez            #+#    #+#             */
/*   Updated: 2024/03/27 14:50:17 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, SIZE1, SIZE2, "fractol");
    fractal->img = mlx_new_image(fractal->mlx, SIZE1, SIZE2);
    fractal->range = 2;
    fractal->max = 42;
}

double	map(float r1[2], float r2[2], float val)
{
	float	new;

	new = (val - r1[0]) / (r1[1] - r1[0]) * (r2[1] - r2[0]) + r2[0];
	return (new);
}

void    mandelbrot(t_fractal *fractal, double x, double y)
{
    float   res;

    res = SIZE1 / SIZE2;
    fractal->zr = 0;
    fractal->zi = 0;
    fractal->cr = map((float [2]){0, SIZE1}, \
	(float [2]){-fractal->range * res, fractal->range * res}, x);
	fractal->ci = map((float [2]){0, SIZE2}, \
	(float [2]){-fractal->range, fractal->range}, y);
}

/*void    julia(t_fractal *fractal, double x, double y)
{}*/

void    name(t_fractal *fractal, char **argv)
{
    if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
    {
        fractal->name = "Mandelbrot";
    }
    /*else if (ft_strncmp(argv[1], "Julia", 5))
        fractal->name = "Julia";*/
    else
    {
        write(1, "Veuillez entrer un nom valable parmis : Mandelbrot et Julia\n", 60);
        exit(EXIT_FAILURE);
    }
}