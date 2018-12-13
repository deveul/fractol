/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:15:17 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 14:23:12 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_put_infos_color(t_fractol *f)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strjoinfreesec("R : ", ft_itoa(f->r))))
		exit(-1);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH - WIDTH / 10), \
			(HEIGHT + HEIGHT / 100), 16777215, str);
	ft_strdel(&str);
	if (!(str = ft_strjoinfreesec("G : ", ft_itoa(f->g))))
		exit(-1);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH - WIDTH / 10), \
			(HEIGHT + HEIGHT / 40), 16777215, str);
	ft_strdel(&str);
	if (!(str = ft_strjoinfreesec("B : ", ft_itoa(f->b))))
		exit(-1);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH - WIDTH / 10), \
			(HEIGHT + HEIGHT / 25), 16777215, str);
	ft_strdel(&str);
}

static void	ft_put_infos_complex(t_fractol *f)
{
	char	*str;

	str = NULL;
	asprintf(&str, "C_R : %f", f->cr);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH / 2), \
			(HEIGHT + HEIGHT / 100), 16777215, str);
	ft_strdel(&str);
	asprintf(&str, "C_I : %f", f->ci);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH / 2), \
			(HEIGHT + HEIGHT / 33), 16777215, str);
	ft_strdel(&str);
}

void		ft_put_infos(t_fractol *f)
{
	char	*str;

	str = NULL;
	asprintf(&str, "Zoom : %f", f->currentzoom);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH / 10), \
			(HEIGHT + HEIGHT / 100), 16777215, str);
	ft_strdel(&str);
	if (!(str = ft_itoa(f->max_iter)))
		exit(-1);
	if (!(str = ft_strjoinfreesec("Iteration : ", str)))
		exit(-1);
	mlx_string_put(f->mlxptr, f->mlxwin, (WIDTH / 10), \
			(HEIGHT + HEIGHT / 33), 16777215, str);
	ft_strdel(&str);
	if (f->param == 1 || f->param == 3)
		ft_put_infos_complex(f);
	ft_put_infos_color(f);
}
