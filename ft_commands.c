/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 20:17:58 by vrenaudi         ###   ########.fr       */
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
	f->xmin = -2;
	f->xmax = 1;
	f->ymin = -1.2;
	f->ymax = f->ymin + (f->xmax - f->xmin) * HEIGHT / WIDTH;
	f->ms = 10;
	f->max_iter = 100;
	if (f->param == 1)
	{
		f->ci = 0.6;
		f->cr = 0.4;
	}
	return (0);
}

static int		ft_reset_color(t_fractol *f)
{
	f->r = 10;
	f->b = 1;
	f->g = 5;
	return (0);
}

static int		ft_switch_trigger(t_fractol *f)
{
	if (f->trigger == 1)
		f->trigger = 0;
	else
		f->trigger = 1;
	return (0);
}

int				ft_commands(int keycode, t_fractol *f)
{
	ft_printf("%d\n", keycode);
	if (keycode == 53 || keycode == 5 || keycode == 11 || keycode == 15
			|| keycode == 17 || keycode == 3 || keycode == 9
			|| keycode == 29 || keycode == 24 || keycode == 27
			|| keycode == 13 || keycode == 14 || keycode == 49
			|| ((keycode == 69 || keycode == 67) && f->max_iter < 10000)
			|| keycode == 257 || (keycode == 78 && f->max_iter > 15)
			|| (keycode == 75 && f->max_iter > 65))
		f->change = 1;
	else
		return (-1);
	if (keycode == 53)
		ft_quit(f);
	else if (keycode == 29)
		ft_reset(f);
	else if (keycode == 257)
		ft_reset_color(f);
	else if (keycode == 49)
		ft_switch_trigger(f);
	else
		ft_commands2(keycode, f);
	return (0);
}
