/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 11:34:30 by vrenaudi         ###   ########.fr       */
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

int				ft_commands(int keycode, t_fractol *f)
{
	if (keycode == 53)
		ft_quit(f);
	else if (keycode == 5 || keycode == 11 || keycode == 15)
		ft_switch_color(keycode, f);
	else if (keycode == 29)
		ft_reset(f);
	ft_printf("%d\n", keycode);
	return (0);
}
