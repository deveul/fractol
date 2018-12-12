/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:27:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 15:42:37 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_horizontal_movements(t_fractol *f)
{
	double	move_x;

	move_x = (f->xmax - f->xmin) / (WIDTH / f->ms);
	if (f->move_l == 1)
	{
		f->xmin -= move_x;
		f->xmax -= move_x;
	}
	if (f->move_r == 1)
	{
		f->xmin += move_x;
		f->xmax += move_x;
	}
}

static void		ft_vertical_movements(t_fractol *f)
{
	double	move_y;

	move_y = (f->ymax - f->ymin) / (HEIGHT / f->ms);
	if (f->move_d == 1)
	{
		f->ymin -= move_y;
		f->ymax -= move_y;
	}
	if (f->move_u == 1)
	{
		f->ymin += move_y;
		f->ymax += move_y;
	}
}

int				ft_loop(t_fractol *f)
{
	if (f->change == 1)
	{
		f->pos = 0;
		mlx_clear_window(f->mlxptr, f->mlxwin);
		ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
		ft_horizontal_movements(f);
		ft_vertical_movements(f);
		if (f->param == 0)
			ft_mandelbrot(f);
		else if (f->param == 1)
			ft_julia(f);
		mlx_put_image_to_window(f->mlxptr, f->mlxwin, f->mlxima, 0, 0);
		f->change = 0;
	}
	return (0);
}
