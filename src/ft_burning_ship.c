/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/12 15:52:16 by vrenaudi         ###   ########.fr       */
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

static void	ft_burning_ship_5(t_fractol *f)
{
	t_tab	t;
	int		i;
	double	refactor;
	double	imfactor;
	double	tmp;

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
			{
				tmp = f->zr;
				f->zr = fabs(pow(f->zr, 5) - (10 * pow(f->zr, 3) * pow(f->zi, 2))
						+ (5 * f->zr * pow(f->zi, 4)) + f->cr);
				f->zi = fabs((5 * pow(tmp, 4) * f->zi)
						- (10 * pow(tmp, 2) * pow(f->zi, 3)) + pow(f->zi, 5) + f->ci);
			}
			ft_draw_pixel(f, i);
		}
	}
}

static void	ft_burning_ship_3(t_fractol *f)
{
	t_tab	t;
	int		i;
	double	refactor;
	double	imfactor;
	double	tmp;

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
			{
				tmp = f->zr;
				f->zr = fabs((f->zr * f->zr * f->zr)
						- (3 * f->zr * f->zi * f->zi) + f->cr);
				f->zi = fabs((3 * tmp * tmp * f->zi) - (f->zi * f->zi * f->zi) + f->ci);
			}
			ft_draw_pixel(f, i);
		}
	}
}

static void	ft_burning_ship_2(t_fractol *f)
{
	t_tab	t;
	int		i;
	double	refactor;
	double	imfactor;
	double	tmp;

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
			{
				tmp = f->zr;
				f->zr = fabs(f->zr * f->zr - f->zi * f->zi + f->cr);
				f->zi = fabs(2 * tmp * f->zi + f->ci);
			}
			ft_draw_pixel(f, i);
		}
	}
}

void		ft_burning_ship(t_fractol *f)
{
	if (f->mand == 2)
		ft_burning_ship_2(f);
	else if (f->mand == 3)
		ft_burning_ship_3(f);
	else if (f->mand == 4)
		ft_burning_ship_5(f);
}
