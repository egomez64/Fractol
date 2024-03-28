#include "fractol.h"

void    which_fractal(t_fractal *fractal)
{
    if (ft_strncmp(fractal->name, "Mandelbrot", 11) == 0)
        result(fractal, mandelbrot);
    /*else if (ft_strncmp(fractal->name, "Julia", 5) == 0)
        result(fractal, julia());*/
}

int num_rep(t_fractal *fractal)
{
    double   tmp;
    int     i;

    i = 0;
    while (i < fractal->max && sqrt(fractal->zr * fractal->zr + fractal->zi * fractal->zi) < 2)
    {
        tmp = fractal->zr;
        fractal->zr = fractal->zr * fractal->zr - fractal->zi * fractal->zi + fractal->cr;
        fractal->zi = tmp * fractal->zi * 2 + fractal->ci;
        i++;
    }
    if (i == fractal->max)
        return (0);
    return (i);
}

void    draw(t_fractal fractal, int repeat, double x, double y)
{
    if (repeat > 0)
        mlx_set_image_pixel(fractal.mlx, fractal.img, x, y, 0xFFFFFFFF);
    else
        mlx_set_image_pixel(fractal.mlx, fractal.img, x, y, 0xFF000000);
}

void    result(t_fractal *fractal, void (*fract)())
{
    double x;
    double y;
    int     repeat;

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