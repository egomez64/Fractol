#include "fractol.h"

int dot(const char *chain)
{
    int dot;
    int after_dot;
    int i;

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

double   ft_atod(const char *nptr)
{
    double after_dot = dot(nptr);
    double	conv;
	int	i;
	double	sign;

	conv = 0;
	i = 0;
	sign = 1;
	while (*nptr && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
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