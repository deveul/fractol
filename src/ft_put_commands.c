/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:15:17 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/01/16 15:38:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	ft_put_commands_2(t_fractol *f)
{
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 330, 16777215, "+1000 : 'F19'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 350, 16777215, "-1000 : 'F18'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 370, 16777215,\
			"Color Palett (num pad) : [0-9]");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 390, 16777215, "Reset : '0'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 410, 16777215,\
			"Switch fractal : Enter");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 430, 16777215,\
			"Change set (Julia) : Mouse mvt");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 450, 16777215, "Exit : Escape");
}

static void	ft_put_commands(t_fractol *f)
{
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 10, 16777215,\
			"Movements : arrow keys");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 30, 16777215,\
			"increase speed mvt : 'e'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 50, 16777215,\
			"decrease speed mvt: 'w'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 70, 16777215,\
			"zoom in : scroll down");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 90, 16777215,\
			"zoom out : scroll up");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 110, 16777215, "more red : 't'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 130, 16777215, "less red : 'r'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 150, 16777215,\
			"more green : 'g'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 170, 16777215,\
			"less green : 'f'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 190, 16777215, "more blue : 'b'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 210, 16777215, "less blue : 'v'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 230, 16777215, "Iterations :");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 250, 16777215, "+10 : '+'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 270, 16777215, "-10 : '-'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 290, 16777215, "+50 : '*'");
	mlx_string_put(f->mlxptr, f->mlxwin2, 10, 310, 16777215, "-50 : '/'");
	ft_put_commands_2(f);
}

void		ft_display_commands(t_fractol *f)
{
	if (!(f->mlxwin2 = mlx_new_window(f->mlxptr, 350, 485, "Commands")))
		exit(-1);
	ft_put_commands(f);
}
