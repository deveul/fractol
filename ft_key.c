/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 14:01:13 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_up(int keycode, t_fractol *f)
{
	if (keycode == 123)
		f->move_l = 0;
	if (keycode == 124)
		f->move_r = 0;
	if (keycode == 126)
		f->move_d = 0;
	if (keycode == 125)
		f->move_u = 0;
	else
		ft_commands(keycode, f);
	return (0);
}

int		ft_key_down(int keycode, t_fractol *f)
{
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		f->change = 1;
	if (keycode == 123)
		f->move_l = 1;
	if (keycode == 124)
		f->move_r = 1;
	if (keycode == 126)
		f->move_d = 1;
	if (keycode == 125)
		f->move_u = 1;
	return (0);
}
