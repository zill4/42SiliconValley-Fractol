
#include "fractol.h"

int			fract_bs(t_data *d, double x, double y)
{
	double	zr;
	double	zi;
	double	zrsqr;
	double	zisqr;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	y = ((-4 * (1 - y / WINDOW_SIZE_Y) + 2) / d->scale) -
		((d->ytrans / WINDOW_SIZE_Y));
	zr = 0;
	zi = 0;
	zrsqr = zr * zr;
	zisqr = zi * zi;
	iters = -1;
	while (zrsqr + zisqr <= 4.0 && ++iters < d->max)
	{
		zi = (fabs(zr) + fabs(zi)) * (fabs(zr) + fabs(zi)) - zrsqr - zisqr;
		zi += y;
		zr = zrsqr - zisqr + x;
		zrsqr = zr * zr;
		zisqr = zi * zi;
	}
	return (iters);
}

int			fract_bsjulia(t_data *d, double x, double y)
{
	double	za;
	double	zb;
	double	temp;
	int		i;

	za = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	zb = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y));
	i = -1;
	while (za * za + zb * zb <= 4 && ++i < d->max)
	{
		temp = za;
		za = fabs(za * za - zb * zb) + d->ca;
		zb = 2 * temp * zb + d->cb;
	}
	return (i);
}
