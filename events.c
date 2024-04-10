#include "fractol.h"

void	zoom(t_fractal *fractal)
{
	int	r_xm;
	int	r_ym;

	mlx_mouse_get_pos(fractal->mlx, &r_xm, &r_ym);
	fractal->range *= 0.9;
	fractal->xm += map((float [2]){0, SIZE1}, \
	(float [2]){-fractal->range, fractal->range}, r_xm) * 0.2;
	fractal->ym += map((float [2]){0, SIZE2}, \
	(float [2]){-fractal->range, fractal->range}, r_ym) * 0.2;
	result(fractal, fractal->render_func);
}

void	unzoom(t_fractal *fractal)
{
	int	r_xm;
	int	r_ym;

	mlx_mouse_get_pos(fractal->mlx, &r_xm, &r_ym);
	fractal->range /= 0.9;
    fractal->xm += map((float [2]){0, SIZE1}, \
	(float [2]){-fractal->range, fractal->range}, r_xm) * 0.2;
	fractal->ym += map((float [2]){0, SIZE2}, \
	(float [2]){-fractal->range, fractal->range}, r_ym) * 0.2;
	result(fractal, fractal->render_func);
}