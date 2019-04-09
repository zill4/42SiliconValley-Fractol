/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 16:06:16 by mhurd             #+#    #+#             */
/*   Updated: 2016/11/09 18:21:32 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "libgfx.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <time.h>

/*
** KEYS
*/
# define KEY_ESC 			0x35
# define KEY_SPACE			0x31
# define KEY_PAD_PLUS		14
# define KEY_PAD_MINUS		15
# define KEY_LEFT			0x7B
# define KEY_RIGHT			0x7C
# define KEY_DOWN			0x7D
# define KEY_UP				0x7E
# define KEY_MOUSE_CLIC_L	0x01
# define KEY_MOUSE_CLIC_R	0x02
# define KEY_MOUSE_UP		0x05
# define KEY_MOUSE_DOWN		0x04
# define NUM_1				12
# define NUM_2				13

typedef struct	s_args
{
	t_data	*d;
	int		start;
	int		end;
}				t_args;

t_plot			*parse_file(char *filename);
void			draw_everything(t_data *d);
int				key_hook(int keycode, t_data *d);
void			draw_reload(t_data *d);
void			ft_exit(void);
void			ft_malloc_error(void);
void			ft_map_error(void);
void			ft_arg_error(void);
void			ft_error(void);
int				fract_julia(t_data *d, double x, double y);
int				mouse_hook(int button, int x, int y, t_data *d);
void			draw_fract(t_data *d);
int				mouse_move(int x, int y, t_data *d);
int				fract_mb(t_data *d, double x, double y);
int				fract_bs(t_data *d, double x, double y);
int				fract_quad(t_data *d, double x, double y);
int				fract_wall(t_data *d, double x, double y);
int				fract_cos(t_data *d, double x, double y);
int				fract_sin(t_data *d, double x, double y);
int				fract_phoenix(t_data *d, double x, double y);
int				fract_bsjulia(t_data *d, double x, double y);
void			free_all(t_data *d);
#endif
