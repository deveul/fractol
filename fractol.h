/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:23:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/10 13:54:31 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900

typedef struct		s_fractol
{
	void			*mlxptr;
	void			*mlxwin;
	void			*mlxima;
	char			*strima;
	int				change;
	int				max_iter;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	double			start_x;
	double			start_y;
	double			z;
	int				move_l;
	int				move_r;
	int				move_d;
	int				move_u;
	int				increaseiter;
	int				decreaseiter;
	int				color;
	int				zoom_in;
	int				zoom_out;
}					t_fractol;

typedef struct		s_mand
{
	int				x;
	int				y;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
}					t_mand;

void				ft_mandelbrot(t_fractol *f);
void				ft_julia(t_fractol *f);
int					ft_loop(t_fractol *f);
int					ft_key_down(int keycode, t_fractol *f);
int					ft_key_up(int keycode, t_fractol *f);
int					ft_commands(int keycode, t_fractol *f);

#endif
