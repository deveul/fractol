/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:20:10 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 11:38:14 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_fractol(t_fractol *f)
{
	f->mlxptr = NULL;
	f->mlxwin = NULL;
	f->mlxima = NULL;
	f->strima = NULL;
	f->z = 0.8;
	f->start_x = -0.75;
	f->start_y = 0.0;
	f->move_l = 0;
	f->move_r = 0;
	f->move_d = 0;
	f->move_u = 0;
	f->max_iter = 100;
	f->increaseiter = 0;
	f->decreaseiter = 0;
	f->color = 0;
}

int			main(int argc, char **argv)
{
	t_fractol	f;
	int			bpp;
	int			s_l;
	int			endian;

	if (argc != 2)
	{
		ft_printf("invalid number of arguments\n");
		return (-1);
	}
	ft_init_fractol(&f);
	f.mlxptr = mlx_init();
	f.mlxwin = mlx_new_window(f.mlxptr, WIDTH, HEIGHT, argv[1]);
	f.mlxima = mlx_new_image(f.mlxptr, WIDTH, HEIGHT);
	f.strima = mlx_get_data_addr(f.mlxima, &(bpp), &(s_l), &(endian));
	if (ft_strequ(argv[1], "Mandelbrot"))
		ft_mandelbrot(&f);
	else if (ft_strequ(argv[1], "Julia"))
		ft_julia(&f);
	mlx_hook(f.mlxwin, 2, 0, ft_key_down, &f);
	mlx_hook(f.mlxwin, 3, 0, ft_key_up, &f);
	mlx_loop_hook(f.mlxptr, ft_loop, &f);
	mlx_loop(f.mlxptr);
	return (0);
}
