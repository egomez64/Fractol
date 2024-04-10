/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:50:15 by egomez            #+#    #+#             */
/*   Updated: 2024/03/27 14:50:17 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int key, void *mlx)
{
    if (key == ESC)
        mlx_loop_end(mlx);
    return (0);
}

int window_hook(int key, void *mlx)
{
    if (key == 0)
        mlx_loop_end(mlx);
    return (0);
}

int scroll_hook(int key, void *fractal)
{
    if (key == 1)
    {
        write(1, "zoom\n", 5);
        zoom(fractal);
    }
    else if (key == 2)
    {
        write(1, "dezoom\n", 7);
        unzoom(fractal);
    }
    return (0);
}