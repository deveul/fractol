/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:27:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/07 15:59:04 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_movements(t_fractol *f)
{
	if (f->move_l == 1)
		f->start_x -= 0.01;
	if (f->move_r == 1)
		f->start_x += 0.01;
	if (f->move_d == 1)
		f->start_y -= 0.01;
	if (f->move_u == 1)
		f->start_y += 0.01;
	return (0);
}

static int		ft_change_max_iter(t_fractol *f)
{
	if (f->increaseiter == 1 && f->max_iter < 1000)
		f->max_iter += 10;
	if (f->decreaseiter == 1 && f->max_iter > 15)
		f->max_iter -= 10;
	return (0);
}

static int		ft_z_in_and_out(t_fractol *f)
{
	if (f->zoom_in == 1)
		f->z += 0.1;
	if (f->zoom_out == 1)
		f->z -= 0.1;
	return (0);
}

int				ft_loop(t_fractol *f)
{
	mlx_clear_window(f->mlxptr, f->mlxwin);
	ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
	ft_movements(f);
	ft_change_max_iter(f);
	ft_z_in_and_out(f);
	ft_mandelbrot(f);
	mlx_put_image_to_window(f->mlxptr, f->mlxwin, f->mlxima, 0, 0);
	return (0);
}
