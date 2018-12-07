/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/07 15:58:32 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_up(int keycode, t_fractol *f)
{
	if (keycode == 123)
		f->move_l = 0;
	if (keycode == 124)
		f->move_r = 0;
	if (keycode == 125)
		f->move_d = 0;
	if (keycode == 126)
		f->move_u = 0;
	if (keycode == 69)
		f->increaseiter = 0;
	if (keycode == 78)
		f->decreaseiter = 0;
	if (keycode == 24)
		f->zoom_in = 0;
	if (keycode == 27)
		f->zoom_out = 0;
	else
		ft_commands(keycode, f);
	return (0);
}

int		ft_key_down(int keycode, t_fractol *f)
{
	if (keycode == 123)
		f->move_l = 1;
	if (keycode == 124)
		f->move_r = 1;
	if (keycode == 125)
		f->move_d = 1;
	if (keycode == 126)
		f->move_u = 1;
	if (keycode == 69)
		f->increaseiter = 1;
	if (keycode == 78)
		f->decreaseiter = 1;
	if (keycode == 24)
		f->zoom_in = 1;
	if (keycode == 27)
		f->zoom_out = 1;
	return (0);
}
