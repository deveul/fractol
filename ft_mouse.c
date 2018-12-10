/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:49:01 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 17:35:47 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int button, int x, int y, t_fractol *f)
{
	double	w;
	double	h;

	w = (double)x;
	h = (double)y;
	if (button == 4 || button == 5)
	{
	//	w = w - (WIDTH / 2);
	//	f->start_x += w / WIDTH;
	//	h = h - (HEIGHT / 2);
	//	f->start_y += h / HEIGHT;
		f->change = 1;
	}
	if (button == 4)
		f->z /= 1.1;
	if (button == 5)
		f->z *= 1.1;
	ft_printf("button : %d\n", button);
	return (0);
}
