
#include "fractol.h"

static	void	mouse_hook_scale(int keycode, int x, int y, t_data *d)
{
	if (keycode == KEY_MOUSE_CLIC_L || keycode == KEY_MOUSE_UP)
	{
		x -= WINDOW_SIZE_X / 2;
		y -= WINDOW_SIZE_Y / 2;
		d->scale *= 1.1;
		d->xtrans += x / d->scale / 2.51;
		d->ytrans -= y / d->scale / 2.51;
	}
	else if (keycode == KEY_MOUSE_CLIC_R || keycode == KEY_MOUSE_DOWN)
		d->scale /= (d->scale > 0.2 ? 1.1 : 1);
}

int				mouse_move(int x, int y, t_data *d)
{
	if (!d->paused)
	{
		x -= WINDOW_SIZE_X / 2;
		y -= WINDOW_SIZE_X / 2;
		d->ca = ((float)x / WINDOW_SIZE_X) * 2;
		d->cb = ((float)y / WINDOW_SIZE_Y) * 2;
		draw_reload(d);
	}
	return (0);
}

int				mouse_hook(int button, int x, int y, t_data *d)
{
	mouse_hook_scale(button, x, y, d);
	draw_reload(d);
	return (0);
}

int				key_hook(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		free_all(d);
		exit(0);
	}
	else if (keycode == KEY_SPACE)
		d->paused = !d->paused;
	else if (keycode == KEY_PAD_PLUS)
		d->max *= 1.1;
	else if (keycode == KEY_PAD_MINUS)
		d->max /= (d->max > 10) ? 1.1 : 1;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		d->xtrans -= ((keycode == KEY_LEFT) ? 100 : -100) / d->scale;
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		d->ytrans -= ((keycode == KEY_DOWN) ? 100 : -100) / d->scale;
	else if (keycode == NUM_2 || keycode == NUM_1)
		d->color_offset -= ((keycode == NUM_2) ? 0.1 : -0.1);
	draw_reload(d);
	return (0);
}
