/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:49:01 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/11 15:40:01 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int button, int x, int y, t_fractol *f)
{
	double	r;
	double	i;
	double	interpolation;

	r = (double)x / (WIDTH / (f->xmax - f->xmin)) + f->xmin;
	i = (double)y / (HEIGHT / (f->ymax - f->ymin)) + f->ymin;
	interpolation = 1.0 / f->zoom;
	if (button == 4 || button == 5)
		f->change = 1;
	if (button == 4)
	{
		f->xmin = r + ((f->xmin - r) * interpolation);
		f->ymin = i + ((f->ymin - i) * interpolation);
		f->xmax = r + ((f->xmax - r) * interpolation);
		f->ymax = i + ((f->ymax - i) * interpolation);
		f->z /= 1.1;
	}
	if (button == 5)
	{
		f->xmin = r + ((f->xmin - r) / interpolation);
		f->ymin = i + ((f->ymin - i) / interpolation);
		f->xmax = r + ((f->xmax - r) / interpolation);
		f->ymax = i + ((f->ymax - i) / interpolation);
		f->z *= 1.1;
	}
	ft_printf("button : %d\n", button);
	return (0);
}
