/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:06:30 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 17:27:03 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		ft_switch_colors3(int keycode, t_fractol *f)
{
	if (keycode == 91)
	{
		f->r = 3;
		f->g = 12;
		f->b = 60;
	}
	else if (keycode == 92)
	{
		f->r = 25;
		f->g = 7;
		f->b = 7;
	}
}

static void	ft_switch_colors2(int keycode, t_fractol *f)
{
	if (keycode == 86)
	{
		f->r = 43;
		f->g = 55;
		f->b = 84;
	}
	else if (keycode == 87)
	{
		f->r = 3;
		f->g = 25;
		f->b = 5;
	}
	else if (keycode == 88)
	{
		f->r = 5;
		f->g = 5;
		f->b = 10;
	}
	else if (keycode == 89)
	{
		f->r = 4;
		f->g = 11;
		f->b = 11;
	}
	ft_switch_colors3(keycode, f);
}

void		ft_switch_colors(int keycode, t_fractol *f)
{
	if (keycode == 82)
	{
		f->r = 222;
		f->g = 222;
		f->b = 222;
	}
	else if (keycode == 83)
	{
		f->r = 222;
		f->g = 0;
		f->b = 187;
	}
	else if (keycode == 84)
	{
		f->r = 180;
		f->g = 200;
		f->b = 209;
	}
	else if (keycode == 85)
	{
		f->r = 11;
		f->g = 84;
		f->b = 79;
	}
	ft_switch_colors2(keycode, f);
}
