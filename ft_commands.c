/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/11 16:05:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_quit(t_fractol *f)
{
	mlx_clear_window(f->mlxptr, f->mlxwin);
	ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
	exit(0);
	return (0);
}

static int		ft_reset(t_fractol *f)
{
	f->xmin = -2.4;
	f->xmax = 2.4;
	f->ymin = -1.5;
	f->ymax = 1.5;
	f->z = 0.8;
	f->ms = 10;
	f->max_iter = 100;
	return (0);
}

static int		ft_reset_color(t_fractol *f)
{
	f->r = 10;
	f->b = 1;
	f->g = 5;
	return (0);
}

static int		ft_switch_color(int keycode, t_fractol *f)
{
	if (keycode == 17 && f->r < 251)
		f->r += 5;
	else if (keycode == 15 && f->r > 4)
		f->r -= 5;
	else if (keycode == 5 && f->g < 251)
		f->g += 5;
	else if (keycode == 3 && f->g > 4)
		f->g -= 5;
	else if (keycode == 11 && f->g < 251)
		f->b += 5;
	else if (keycode == 9 && f->b > 4)
		f->b -= 5;
	return (0);
}

static int		ft_change_max_iter(int keycode, t_fractol *f)
{
	if (keycode == 69)
		f->max_iter += 10;
	else if (keycode == 67)
		f->max_iter += 50;
	else if (keycode == 78)
		f->max_iter -= 10;
	else if (keycode == 75)
		f->max_iter -= 50;
	ft_printf("iter is : %d\n", f->max_iter);
	return (0);
}

static int		ft_z_in_and_out(int keycode, t_fractol *f)
{
	if (keycode == 24)
	{
		f->xmin /= f->zoom;
		f->xmax /= f->zoom;
		f->ymin /= f->zoom;
		f->ymax /= f->zoom;
		f->z *= 1.1;
	}
	if (keycode == 27)
	{
		f->xmin *= f->zoom;
		f->xmax *= f->zoom;
		f->ymin *= f->zoom;
		f->ymax *= f->zoom;
		f->z /= 1.1;
	}
	printf("zoom is : %f\n", f->z);
	return (0);
}

static int		ft_change_move_speed(int keycode, t_fractol *f)
{
	if (keycode == 13 && f->ms > 5)
		f->ms -= 5;
	else
		f->ms += 5;
	return (0);
}

int				ft_commands(int keycode, t_fractol *f)
{
	if (keycode == 53 || keycode == 5 || keycode == 11 || keycode == 15
			|| keycode == 17 || keycode == 3 || keycode == 9
			|| keycode == 29 || keycode == 24 || keycode == 27
			|| keycode == 13 || keycode == 14
			|| ((keycode == 69 || keycode == 67) && f->max_iter < 10000)
			|| keycode == 257 || (keycode == 78 && f->max_iter > 15)
			|| (keycode == 75 && f->max_iter > 65))
		f->change = 1;
	if (keycode == 53)
		ft_quit(f);
	else if (keycode == 5 || keycode == 11 || keycode == 15 
			|| keycode == 17 || keycode == 3 || keycode == 9)
		ft_switch_color(keycode, f);
	else if (keycode == 29)
		ft_reset(f);
	else if (keycode == 257)
		ft_reset_color(f);
	else if (((keycode == 69 || keycode == 67) && f->max_iter < 10000)
			|| (keycode == 75 && f->max_iter > 65)
			|| (keycode == 78 && f->max_iter > 15))
		ft_change_max_iter(keycode, f);
	else if (keycode == 24 || keycode == 27)
		ft_z_in_and_out(keycode, f);
	else if (keycode == 13 || keycode == 14)
		ft_change_move_speed(keycode, f);
	ft_printf("%d\n", keycode);
	return (0);
}
