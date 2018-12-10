/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:27:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 11:38:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_movements(t_fractol *f)
{
	double	move;

	move = 0.1 / f->z;
	if (f->move_l == 1)
		f->start_x -= move;
	if (f->move_r == 1)
		f->start_x += move;
	if (f->move_d == 1)
		f->start_y -= move;
	if (f->move_u == 1)
		f->start_y += move;
	return (0);
}

static int		ft_change_max_iter(t_fractol *f)
{
	if (f->increaseiter == 1 && f->max_iter < 1000)
		f->max_iter += 10;
	if (f->decreaseiter == 1 && f->max_iter > 15)
		f->max_iter -= 10;
	ft_printf("iter is : %d\n", f->max_iter);
	return (0);
}

static int		ft_z_in_and_out(t_fractol *f)
{
	if (f->zoom_in == 1)
		f->z *= 1.5;
	if (f->zoom_out == 1)
		f->z /= 1.5;
	printf("zoom is : %f\n", f->z);
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
