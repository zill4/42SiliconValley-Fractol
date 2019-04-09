
#include "fractol.h"

void	free_all(t_data *d)
{
	int y;

	y = -1;
	while (++y <= WINDOW_SIZE_Y)
		free(d->image[y]);
}

void	ft_exit(void)
{
	exit(1);
}

void	ft_malloc_error(void)
{
	ft_putendl_fd("Malloc Failure", 2);
	ft_exit();
}

void	ft_arg_error(void)
{
	ft_putendl_fd("Missing filename.", 2);
	ft_exit();
}

void	ft_error(void)
{
	// ft_putendl_fd(strerror(errno), 2);
	ft_exit();
}
