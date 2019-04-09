#include "fractol.h"

int			fract_quad(t_data *d, double x, double y)
{
	double	zr;
	double	zi;
	double	a;
	double	b;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	y = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y));
	a = 0;
	b = 0;
	iters = -1;
	while (a * a + b * b <= 4.0 && ++iters < d->max)
	{
		zi = (a * a * a * a) - (6 * a * a * b * b) + (b * b * b * b) + x;
		zr = (4 * a * a * a * b) - (4 * a * b * b * b) + y;
		a = zi;
		b = zr;
	}
	return (iters);
}

int			fract_cos(t_data *d, double x, double y)
{
	double	zr;
	double	zi;
	double	a;
	double	b;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	y = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y));
	a = 0;
	b = 0;
	iters = -1;
	while (a * a + b * b <= 4.0 && ++iters < d->max)
	{
		zi = -sin(b) * sinh(a) + x;
		zr = cos(b) * cosh(a) + y;
		a = zi;
		b = zr;
	}
	return (iters);
}

int			fract_sin(t_data *d, double x, double y)
{
	double	zr;
	double	zi;
	double	a;
	double	b;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	y = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y));
	a = 0;
	b = 0;
	iters = -1;
	while (a * a + b * b <= 4.0 && ++iters < d->max)
	{
		zi = cos(b) * sinh(a) + x;
		zr = sin(b) * cosh(a) + y;
		a = zi;
		b = zr;
	}
	return (iters);
}

int			fract_phoenix(t_data *d, double x, double y)
{
	t_2d	z;
	t_2d	c;
	t_2d	p;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X)) * 0.5667;
	y = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y)) * 0.5667;
	c.x = 1;
	c.y = 0;
	p.x = 0;
	p.y = 0;
	iters = -1;
	while (c.x * c.x + c.y * c.y <= 4.0 && ++iters < d->max)
	{
		z.x = c.x * c.x - c.y * c.y + x + p.x * d->ca;
		z.y = 2 * c.x * c.y + y + p.y * d->ca;
		p.x = c.x;
		p.y = c.y;
		c.x = z.x;
		c.y = z.y;
	}
	return (iters);
}
