/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:27:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 14:01:16 by vrenaudi         ###   ########.fr       */
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

int				ft_loop(t_fractol *f)
{
	if (f->change == 1)
	{
		mlx_clear_window(f->mlxptr, f->mlxwin);
		ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
		ft_movements(f);
		ft_mandelbrot(f);
		mlx_put_image_to_window(f->mlxptr, f->mlxwin, f->mlxima, 0, 0);
		f->change = 0;
	}
	return (0);
}
