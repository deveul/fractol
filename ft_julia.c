/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/11 14:37:27 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_draw_pixel(t_fractol *f, int i)
{
	f->strima[f->pos] = (char)((f->b * i) % 256);
	f->strima[f->pos + 1] = (char)((f->g * i) % 256);
	f->strima[f->pos + 2] = (char)((f->r * i) % 256);
}

static void	ft_init_while(t_mand *m, double *tmp, int *i)
{
	*(i) = 0;
	m->zr = 0;
	m->zi = 0;
	*(tmp) = 0;
}

void		ft_julia(t_fractol *f)
{
	t_mand	m;
	int		x;
	int		y;
	int		i;
	double	tmp;

	y = -1;
	while (++y < HEIGHT)
	{
		m.ci = f->ymin + (((f->ymax - f->ymin) / HEIGHT) * y);
		x = -1;
		while (++x < WIDTH)
		{
			m.cr = f->xmin + (((f->xmax - f->xmin) / WIDTH) * x);
			ft_init_while(&m, &tmp, &i);
			while (((m.zr * m.zr) + (m.zi * m.zi)) < 4 && i++ < f->max_iter)
			{
				tmp = m.zr;
				m.zr = m.zr * m.zr - m.zi * m.zi + m.cr;
				m.zi = 2 * tmp * m.zi + m.ci;
			}
			if (i < f->max_iter)
				ft_draw_pixel(f, i);
			f->pos += 4;
		}
	}
}
