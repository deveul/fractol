/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 11:29:16 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_draw_pixel(t_fractol *f, int x, int y, int i)
{
	int		pos;

	pos = (4 * x) + (y * WIDTH * 4);
	f->strima[pos + f->color] = (char)(255 * i / f->max_iter);
}

static void	ft_init_while(t_mand *m, double *tmp, int *i)
{
	*(i) = 0;
	m->zr = 0;
	m->zi = 0;
	*(tmp) = 0;
}

void		ft_mandelbrot(t_fractol *f)
{
	t_mand	m;
	int		i;
	double	tmp;

	m.y = -1;
	while (++m.y < HEIGHT)
	{
		m.ci = 1.5 * (m.y - HEIGHT / 2) / (0.5 * f->z * HEIGHT) + f->start_y;
		m.x = -1;
		while (++m.x < WIDTH)
		{
			m.cr = 1.5 * (m.x - WIDTH / 2) / (0.5 * f->z * WIDTH) + f->start_x;
			ft_init_while(&m, &tmp, &i);
			while (((m.zr * m.zr) + (m.zi * m.zi)) < 4 && i++ < f->max_iter)
			{
				tmp = m.zr;
				m.zr = m.zr * m.zr - m.zi * m.zi + m.cr;
				m.zi = 2 * tmp * m.zi + m.ci;
			}
			if (i < f->max_iter)
				ft_draw_pixel(f, m.x, m.y, i);
		}
	}
}
