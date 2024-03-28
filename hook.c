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
    if (key == 41)
        mlx_loop_end(mlx);
    return (0);
}

int window_hook(int key, void *mlx)
{
    if (key == 0)
        mlx_loop_end(mlx);
    return (0);
}