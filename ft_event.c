/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:49:01 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 16:12:13 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_redcross(t_fractol *f)
{
	(void)f;
	exit(0);
}

int		ft_mouse_mvt(int x, int y, t_fractol *f)
{
	if (f->trigger == 1)
	{
		f->change = 1;
		f->cr = f->xmin + x * (f->xmax - f->xmin) / WIDTH;
		f->ci = f->ymin + y * (f->ymax - f->ymin) / HEIGHT;
	}
	return (0);
}

int		ft_mouse(int button, int x, int y, t_fractol *f)
{
	double	r;
	double	i;

	r = (double)x / (WIDTH / (f->xmax - f->xmin)) + f->xmin;
	i = (double)y / (HEIGHT / (f->ymax - f->ymin)) + f->ymin;
	if (button == 4 || button == 5)
		f->change = 1;
	if (button == 4)
	{
		f->currentzoom *= f->zoom;
		f->xmin = r + ((f->xmin - r) * f->invzoom);
		f->ymin = i + ((f->ymin - i) * f->invzoom);
		f->xmax = r + ((f->xmax - r) * f->invzoom);
		f->ymax = i + ((f->ymax - i) * f->invzoom);
	}
	if (button == 5)
	{
		f->currentzoom /= f->zoom;
		f->xmin = r + ((f->xmin - r) / f->invzoom);
		f->ymin = i + ((f->ymin - i) / f->invzoom);
		f->xmax = r + ((f->xmax - r) / f->invzoom);
		f->ymax = i + ((f->ymax - i) / f->invzoom);
	}
	return (0);
}
