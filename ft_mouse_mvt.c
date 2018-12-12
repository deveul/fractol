/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_mvt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:49:01 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 14:27:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
