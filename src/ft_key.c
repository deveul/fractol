/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 17:27:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
	else if (keycode == 17)
		f->r_up = 0;
	else if (keycode == 15)
		f->r_down = 0;
	else if (keycode == 5)
		f->g_up = 0;
	else if (keycode == 3)
		f->g_down = 0;
	else if (keycode == 11)
		f->b_up = 0;
	else if (keycode == 9)
		f->b_down = 0;
	else
		ft_commands(keycode, f);
	return (0);
}

int		ft_key_down(int keycode, t_fractol *f)
{
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126
			|| keycode == 17 || keycode == 15 || keycode == 5
			|| keycode == 3 || keycode == 11 || keycode == 9)
		f->change = 1;
	if (keycode == 123)
		f->move_l = 1;
	if (keycode == 124)
		f->move_r = 1;
	if (keycode == 126)
		f->move_d = 1;
	if (keycode == 125)
		f->move_u = 1;
	else if (keycode == 17)
		f->r_up = 1;
	else if (keycode == 15)
		f->r_down = 1;
	else if (keycode == 5)
		f->g_up = 1;
	else if (keycode == 3)
		f->g_down = 1;
	else if (keycode == 11)
		f->b_up = 1;
	else if (keycode == 9)
		f->b_down = 1;
	return (0);
}
