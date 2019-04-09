
#include "fractol.h"

#include <stdio.h>

void	list_fractals(void)
{
	ft_putendl("Valid fractals:\n\
	J: Julia\n\
	M: Mandelbrot\n\
	B: Burning Ship\n\
	Q: Mandelbrot Z^4\n\
	W: Wall\n\
	C: Cos Mandelbrot\n\
	S: Sin Mandelbrot\n\
	P: Phoenix\n\
	BJ: Burning Julia");
	exit(0);
}

void	display_controls(void)
{
	ft_putendl("CONTROLS:\n\
Zoom:\n\
	IN: Mouse: LClick\n\
		Scroll: Up\n\
		Will zoom at mouse coordinates.\n\
	OUT: Mouse: RClick\n\
		Scroll: Down\n\
Translate:\n\
	Arrow Keys\n\
Modify Julia:\n\
	Mouse coordinates\n\
	Spacebar to lock\n\
Increase Max Iterations:\n\
	Numpad E/R\n\
Change Color Spectrum:\n\
	Numpad Q/W");
}

void	set_fract(t_data *d, char *s)
{
	if (ft_strequ(s, "J"))
		d->fract = (fract_julia);
	else if (ft_strequ(s, "M"))
		d->fract = (fract_mb);
	else if (ft_strequ(s, "B"))
		d->fract = (fract_bs);
	else if (ft_strequ(s, "Q"))
		d->fract = (fract_quad);
	else if (ft_strequ(s, "W"))
		d->fract = (fract_wall);
	else if (ft_strequ(s, "C"))
		d->fract = (fract_cos);
	else if (ft_strequ(s, "S"))
		d->fract = (fract_sin);
	else if (ft_strequ(s, "P"))
		d->fract = (fract_phoenix);
	else if (ft_strequ(s, "BJ"))
		d->fract = (fract_bsjulia);
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = (t_data *)ft_memalloc(sizeof(t_data));
		if (!data)
			ft_malloc_error();
		set_fract(data, av[1]);
		if (!data->fract)
			list_fractals();
		display_controls();
		draw_everything(data);
	}
	else
		list_fractals();
	return (0);
}
