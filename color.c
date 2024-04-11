/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:19:25 by egomez            #+#    #+#             */
/*   Updated: 2024/04/11 12:19:33 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter)
{
	int				index;
	unsigned int	color_palette[5];

	color_palette[0] = 0xffff2a6d;
	color_palette[1] = 0xffd1f7ff;
	color_palette[2] = 0xff05d9e8;
	color_palette[3] = 0xff005678;
	color_palette[4] = 0xff01012b;

	index = iter % 5;
	return (color_palette[index]);
}
