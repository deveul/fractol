/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/11 19:00:58 by vrenaudi         ###   ########.fr       */
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

static void	choose_julia_value(t_fractol *f)
{
	double	tmp;

	tmp = f->zr;
	if (f->mand == 2)
	{
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * tmp * f->zi + f->ci;
	}
	else if (f->mand == 3)
	{
		f->zr = (f->zr * f->zr * f->zr) - (3 * f->zr * f->zi * f->zi) + f->cr;
		f->zi = (3 * tmp * tmp * f->zi) - (f->zi * f->zi * f->zi) + f->ci;
	}
	else if (f->mand == 4)
	{
		f->zr = pow(f->zr, 4) - (6 * pow(f->zr, 2) * pow(f->zi, 2))
			+ pow(f->zi, 4) + f->cr;
		f->zi = (4 * pow(tmp, 3) * f->zi) - (4 * tmp * pow(f->zi, 3)) + f->ci;
	}
}

void		ft_julia(t_fractol *f)
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
			f->zi = j.ymin + t.y * j.imfactor + f->ci;
			f->zr = j.xmin + t.x * j.refactor + f->cr;
			i = 0;
			while (((f->zr * f->zr) + (f->zi * f->zi)) < 4 && i++ < f->max_iter)
				choose_julia_value(f);
			ft_draw_pixel(f, i);
		}
	}
}
