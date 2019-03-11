/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/11 17:30:42 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		ft_quit(t_fractol *f)
{
	mlx_clear_window(f->mlxptr, f->mlxwin);
	mlx_clear_window(f->mlxptr, f->mlxwin2);
	ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
	exit(0);
	return (0);
}

static int		ft_reset(t_fractol *f)
{
	f->xmin = -2;
	f->xmax = 2;
	f->ymin = -2;
	f->ymax = 2;
	f->ms = 10;
	f->max_iter = 100;
	if (f->param == 1 || f->param == 3)
	{
		f->trigger = 1;
		f->ci = 0;
		f->cr = 0;
	}
	f->currentzoom = 1;
	return (0);
}

static void		ft_switch(int keycode, t_fractol *f)
{
	if (keycode == 49)
	{
		if (f->trigger == 1)
			f->trigger = 0;
		else
			f->trigger = 1;
	}
	else
	{
		if (f->param != 3)
			f->param++;
		else
			f->param = 0;
		ft_reset(f);
	}
}

int				ft_commands(int keycode, t_fractol *f)
{
	ft_printf("keycode:%d\n", keycode);
	if (keycode == 53 || keycode == 29 || keycode == 24 || keycode == 27
			|| keycode == 13 || keycode == 14 || keycode == 49
			|| ((keycode == 69 || keycode == 67 || keycode == 80)
				&& f->max_iter < 10000) || (keycode == 75 && f->max_iter > 65)
			|| (keycode == 78 && f->max_iter > 15) || keycode == 36
			|| (keycode == 79 && f->max_iter > 1015)
			|| (keycode > 81 && keycode < 93 && keycode != 90)
			|| keycode == 0 || keycode == 1)
		f->change = 1;
	else
		return (-1);
	if (keycode == 53)
		ft_quit(f);
	else if (keycode == 29)
		ft_reset(f);
	else if (keycode == 36 || keycode == 49)
		ft_switch(keycode, f);
	else
		ft_commands2(keycode, f);
	return (0);
}
