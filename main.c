/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:27 by egomez            #+#    #+#             */
/*   Updated: 2024/03/20 17:37:43 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Veuillez entrer un nom valable parmis : Mandelbrot et Julia\n", 70);
		exit(EXIT_FAILURE);
	}
	t_fractal	fractal;
	init(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	name(&fractal, argv);
	which_fractal(&fractal);
	mlx_set_fps_goal(fractal.mlx, 30);
	mlx_on_event(fractal.mlx, fractal.win, MLX_KEYDOWN, key_hook, fractal.mlx);
	mlx_on_event(fractal.mlx, fractal.win, MLX_WINDOW_EVENT, window_hook, fractal.mlx);
	mlx_loop(fractal.mlx);
	mlx_destroy_window(fractal.mlx, fractal.win);
	mlx_destroy_display(fractal.mlx);
	return (0);
}