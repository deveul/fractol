/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/11 18:58:59 by vrenaudi         ###   ########.fr       */
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

static void	ft_init_while(t_fractol *f, int *i)
{
	*i = 0;
	f->zr = 0;
	f->zi = 0;
}

static void	ft_init_factors(t_fractol *f, double *refactor, double *imfactor)
{
	*refactor = (f->xmax - f->xmin) / WIDTH;
	*imfactor = (f->ymax - f->ymin) / HEIGHT;
}

static void	choose_mandelbrot_value(t_fractol *f)
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

void		ft_mandelbrot(t_fractol *f)
{
	t_tab	t;
	int		i;
	double	refactor;
	double	imfactor;

	ft_init_factors(f, &refactor, &imfactor);
	t.y = -1;
	while (++t.y < HEIGHT)
	{
		f->ci = f->ymin + t.y * imfactor;
		t.x = -1;
		while (++t.x < WIDTH)
		{
			f->cr = f->xmin + t.x * refactor;
			ft_init_while(f, &i);
			while (((f->zr * f->zr) + (f->zi * f->zi)) < 4 && i++ < f->max_iter)
				choose_mandelbrot_value(f);
			ft_draw_pixel(f, i);
		}
	}
}
