/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 13:35:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_draw_pixel(t_fractol *f, int i)
{
	f->strima[f->pos] = (char)((f->b * i) % 256);
	f->strima[f->pos + 1] = (char)((f->g * i) % 256);
	f->strima[f->pos + 2] = (char)((f->r * i) % 256);
}

static void	ft_init_while(t_fractol *f, double *tmp, int *i)
{
	*(i) = 0;
	f->zr = 0;
	f->zi = 0;
	*(tmp) = 0;
}

void		ft_mandelbrot(t_fractol *f)
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
	while (++y < HEIGHT)
	{
		f->ci = f->ymin + y * imfactor;
		x = -1;
		while (++x < WIDTH)
		{
			f->cr = f->xmin + x * refactor;
			ft_init_while(f, &tmp, &i);
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
