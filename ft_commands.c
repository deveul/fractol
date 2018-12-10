/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 14:01:15 by vrenaudi         ###   ########.fr       */
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
	f->z = 0.8;
	f->max_iter = 100;
	f->start_y = 0;
	f->start_x = -0.75;
	f->color = 0;
	return (0);
}

static int		ft_switch_color(int keycode, t_fractol *f)
{
	if (keycode == 15)
		f->color = 2;
	else if (keycode == 5)
		f->color = 1;
	else if (keycode == 11)
		f->color = 0;
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
		f->z *= 1.5;
	if (keycode == 27)
		f->z /= 1.5;
	printf("zoom is : %f\n", f->z);
	return (0);
}

int				ft_commands(int keycode, t_fractol *f)
{
	if (keycode == 53 || keycode == 5 || keycode == 11 || keycode == 15
			|| keycode == 29 || keycode == 24 || keycode == 27
			|| ((keycode == 69 || keycode == 67) && f->max_iter < 1000)
			|| ((keycode == 78 || keycode == 75) && f->max_iter > 15))
		f->change = 1;
	if (keycode == 53)
		ft_quit(f);
	else if (keycode == 5 || keycode == 11 || keycode == 15)
		ft_switch_color(keycode, f);
	else if (keycode == 29)
		ft_reset(f);
	else if (((keycode == 69 || keycode == 67) && f->max_iter < 1000)
			|| ((keycode == 78 || keycode == 75) && f->max_iter > 15))
		ft_change_max_iter(keycode, f);
	else if (keycode == 24 || keycode == 27)
		ft_z_in_and_out(keycode, f);
	ft_printf("%d\n", keycode);
	return (0);
}
