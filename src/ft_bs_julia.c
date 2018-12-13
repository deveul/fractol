/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 17:25:29 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	ft_draw_pixel(t_fractol *f, int i)
{
	if (i < f->max_iter)
	{
		f->strima[f->pos] = (char)((f->b * i) % 256);
		f->strima[f->pos + 1] = (char)((f->g * i) % 256);
		f->strima[f->pos + 2] = (char)((f->r * i) % 256);
	}
	f->pos += 4;
}

static void	ft_init_factors(t_fractol *f, t_julia *j)
{
	j->refactor = (f->xmax - f->xmin) / (WIDTH - 1);
	j->imfactor = (f->ymax - f->ymin) / (HEIGHT - 1);
}

void		ft_bs_julia(t_fractol *f)
{
	t_tab	t;
	t_julia	j;
	int		i;

	j.xmin = f->xmin - f->cr;
	j.ymin = f->ymin - f->ci;
	ft_init_factors(f, &j);
	t.y = -1;
	while (++t.y < HEIGHT)
	{
		t.x = -1;
		while (++t.x < WIDTH)
		{
			f->zi = fabs(j.ymin + t.y * j.imfactor + f->ci);
			f->zr = fabs(j.xmin + t.x * j.refactor + f->cr);
			i = 0;
			while (((f->zr * f->zr) + (f->zi * f->zi)) < 4 && i++ < f->max_iter)
			{
				j.tmp = f->zr;
				f->zr = fabs(f->zr * f->zr - f->zi * f->zi + f->cr);
				f->zi = fabs(2 * j.tmp * f->zi + f->ci);
			}
			ft_draw_pixel(f, i);
		}
	}
}
