

#include "libgfx.h"

void		put_pixel(t_data *d, int x, int y, t_rgb color)
{
	int i;

	i = (x * 4) + (y * d->s_line);
	// d->pixel_img[i] = MIN(255, color.b * 255);
	// d->pixel_img[++i] = MIN(255, color.g * 255);
	// d->pixel_img[++i] = MIN(255, color.r * 255);
	d->pixel_img[i] = color.b * 255;
	d->pixel_img[++i] = color.g * 255;
	d->pixel_img[++i] = color.r * 255;
}

static int	get_color(t_data *d, double iterations)
{
	double			frequency;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	(void)d;
	frequency = M_PI / 20;
	red = (sin(frequency * iterations + d->color_offset) + 1) * 127;
	green = (cos(frequency * iterations + d->color_offset) + 1) * 127;
	blue = (-cos(frequency * iterations + d->color_offset) + 1) * 127;
	return (red << 16 | ((green << 8) & 0xFF00) | (blue & 0xFF));
}

void		color_pixel(t_data *d, int x, int y, int iterations)
{
	unsigned int		color;
	t_rgb				c;

	if (iterations != d->max)
		color = get_color(d, iterations);
	else
		color = 0xFFFFFF;
	c.r = (float)(color >> 16) / 255;
	c.g = (float)((color >> 8) & 0xFF) / 255;
	c.b = (float)(color & 0xFF) / 255;
	d->image[y][x] = c;
}
