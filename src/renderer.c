
#include "fractol.h"

t_rgb	*aa(t_data *d, int y, int x, t_rgb *new)
{
	int		yi;
	int		xi;
	float	count;
	float	weight;

	yi = MAX(-1, y - 2);
	count = 0;
	while (++yi < MIN(WINDOW_SIZE_Y, y + 2))
	{
		xi = MAX(-1, x - 2);
		while (++xi < MIN(WINDOW_SIZE_X, x + 2))
		{
			weight = (xi == x && yi == y) ? 9 : 1;
			new->r += d->image[yi][xi].r * weight;
			new->g += d->image[yi][xi].g * weight;
			new->b += d->image[yi][xi].b * weight;
			count += weight;
		}
	}
	new->r /= count;
	new->g /= count;
	new->b /= count;
	return (new);
}

void	post_process(t_data *d)
{
	int		x;
	int		y;
	t_rgb	new;

	y = -1;
	while (++y < WINDOW_SIZE_Y)
	{
		x = -1;
		while (++x < WINDOW_SIZE_X)
		{
			new.r = 0;
			new.g = 0;
			new.b = 0;
			aa(d, y, x, &new);
			put_pixel(d, x, y, new);
		}
	}
}

void	draw_reload(t_data *d)
{
	int x;

	d->expired = 1;
	d->img = mlx_new_image(d->mlx, WINDOW_SIZE_X + 100, WINDOW_SIZE_Y + 100);
	d->pixel_img = mlx_get_data_addr(d->img, &(d->bpp), &(d->s_line), &(d->ed));
	draw_fract(d);
	x = -1;
	while (++x < d->thread_count)
		pthread_join(d->render_threads[x], NULL);
	post_process(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
	d->expired = 0;
}

int		expose_hook(t_data *d)
{
	if (!d->expired)
		draw_reload(d);
	return (0);
}

void	draw_everything(t_data *d)
{
	int y;

	d->scale = 1.0;
	d->ytrans = 0;
	d->xtrans = 0;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Fractol");
	d->max = 48;
	d->ca = -0.7;
	d->cb = 0.27015;
	d->paused = 0;
	d->image = ft_memalloc(sizeof(t_rgb) * WINDOW_SIZE_Y + 1);
	y = -1;
	while (++y <= WINDOW_SIZE_Y)
		d->image[y] = ft_memalloc(sizeof(t_rgb) * WINDOW_SIZE_X + 1);
	d->thread_count = MIN(16, WINDOW_SIZE_Y * WINDOW_SIZE_X);
	d->render_threads = (pthread_t *)ft_memalloc(sizeof(pthread_t)
		* d->thread_count);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_hook(d->win, 2, 3, key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_hook(d->win, 6, (1L << 6), mouse_move, d);
	mlx_loop(d->mlx);
}
