/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:23:40 by egomez            #+#    #+#             */
/*   Updated: 2024/04/11 12:23:55 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	dot(const char *chain)
{
	int	dot;
	int	after_dot;
	int	i;

	dot = 0;
	after_dot = 0;
	i = 0;
	while (chain[i] != 0)
	{
		if (dot > 0)
			after_dot *= 10;
		if (chain[i] == '.' && dot == 0)
		{
			after_dot = 1;
			dot = 1;
		}
		i++;
	}
	return (after_dot);
}

int	skip(const char *nptr)
{
	int	i;

	i = 0;
	while (*nptr && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	return (i);
}

double	ft_atod(const char *nptr)
{
	double	after_dot;
	double	conv;
	int		i;
	double	sign;

	after_dot = dot(nptr);
	conv = 0;
	i = skip(nptr);
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '.')
		return (0);
	while ((*nptr && nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.')
	{
		if (nptr[i] != '.')
			conv = conv * 10 + (nptr[i] - '0');
		i++;
	}
	return ((conv / after_dot) * sign);
}
