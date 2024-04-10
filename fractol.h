/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:50:15 by egomez            #+#    #+#             */
/*   Updated: 2024/03/27 14:50:17 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "MacroLibX/includes/mlx.h"
# include <math.h>
# define SIZE1 800
# define SIZE2 800
# define ESC 41
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
    void    *mlx;
    void    *win;
    void    *img;
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  xm;
    double  ym;
    double     range;
    char    *name;
    int     max;
    void (*render_func)();
}   t_fractal;

void    init(t_fractal *fractal);
int     key_hook(int key, void *mlx);
int     window_hook(int key, void *mlx);
void    name(t_fractal *fractal, char **argv);
void    mandelbrot(t_fractal *fractal, double x, double y);
double	map(float r1[2], float r2[2], float val);
void    which_fractal(t_fractal *fractal);
void    result(t_fractal *fractal, void (*fract)());
void    draw(t_fractal fractal, int repeat, double x, double y);
int     num_rep(t_fractal *fractal);
void    julia(t_fractal *fractal, double x, double y);
void	zoom(t_fractal *fractal);
void	unzoom(t_fractal *fractal);
int     scroll_hook(int key, void *fractal);
double   ft_atod(const char *nptr);
int    get_color(int iter);

# endif