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

void	errors(int argc, char **argv)
{
	if (argc < 2 || (ft_strncmp(argv[1], "Mandelbrot", 10)
			&& ft_strncmp(argv[1], "Julia", 5)))
	{
		ft_printf("Veuillez entrer un nom de fractal");
		ft_printf(" valable parmis : Mandelbrot et Julia\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc < 4)
	{
		ft_printf("Veuillez entrer les constantes de Julia tel que : ");
		ft_printf("valable parmis : Mandelbrot et Julia\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	errors(argc, argv);
	init(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	name(&fractal, argv);
	which_fractal(&fractal);
	mlx_set_fps_goal(fractal.mlx, 30);
	mlx_on_event(fractal.mlx, fractal.win, MLX_KEYDOWN,
		key_hook, fractal.mlx);
	mlx_on_event(fractal.mlx, fractal.win, MLX_WINDOW_EVENT,
		window_hook, fractal.mlx);
	mlx_on_event(fractal.mlx, fractal.win, MLX_MOUSEWHEEL,
		scroll_hook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_destroy_image(fractal.mlx, fractal.img);
	mlx_destroy_window(fractal.mlx, fractal.win);
	mlx_destroy_display(fractal.mlx);
	return (0);
}
