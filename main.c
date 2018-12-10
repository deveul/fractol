/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:20:10 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 19:57:53 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_fractol(t_fractol *f)
{
	f->mlxptr = NULL;
	f->mlxwin = NULL;
	f->mlxima = NULL;
	f->strima = NULL;
	f->z = 1;
	f->start_x = -0.75;
	f->start_y = 0.0;
	f->move_l = 0;
	f->move_r = 0;
	f->move_d = 0;
	f->move_u = 0;
	f->max_iter = 100;
	f->color = 1;
	f->change = 0;
	f->pos = 0;
	f->r = 10;
	f->b = 1;
	f->g = 5;
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
	if (!ft_strequ(argv[1], "Mandelbrot") && !ft_strequ(argv[1], "Julia"))
	{
		ft_printf("valid parameters are :\nMandelbrot\nJulia\n");
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
	mlx_put_image_to_window(f.mlxptr, f.mlxwin, f.mlxima, 0, 0);
	mlx_hook(f.mlxwin, 2, 0, ft_key_down, &f);
	mlx_hook(f.mlxwin, 3, 0, ft_key_up, &f);
	mlx_hook(f.mlxwin, 4, 0, ft_mouse, &f);
	mlx_loop_hook(f.mlxptr, ft_loop, &f);
	mlx_loop(f.mlxptr);
	return (0);
}
