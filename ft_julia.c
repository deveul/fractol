/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 13:47:28 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_draw_pixel(t_fractol *f, int i)
{
	f->strima[f->pos] = (char)((f->b * i) % 256);
	f->strima[f->pos + 1] = (char)((f->g * i) % 256);
	f->strima[f->pos + 2] = (char)((f->r * i) % 256);
}

void		ft_julia(t_fractol *f)
{
	int		x;
	int		y;
	int		i;
	double	tmp;
	double	refactor;
	double	imfactor;

	y = -1;
	refactor = (f->xmax - f->xmin) / WIDTH;
	imfactor = (f->ymax - f->ymin) / HEIGHT;
	f->ci = 0;
	f->cr = -0.75;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->zi = f->ymin + y * imfactor + f->ci;
			f->zr = f->xmin + x * refactor + f->cr;
			i = 0;
			while (((f->zr * f->zr) + (f->zi * f->zi)) < 4 && i++ < f->max_iter)
			{
				tmp = f->zr;
				f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = 2 * tmp * f->zi + f->ci;
			}
			if (i < f->max_iter)
				ft_draw_pixel(f, i);
			f->pos += 4;
		}
	}
}
