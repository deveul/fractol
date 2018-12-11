/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:23:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/11 16:07:14 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1080
# define HEIGHT 720

typedef struct		s_fractol
{
	void			*mlxptr;
	void			*mlxwin;
	void			*mlxima;
	char			*strima;
	int				change;
	int				max_iter;
	int				pos;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			z;
	int				move_l;
	int				move_r;
	int				move_d;
	int				move_u;
	int				color;
	int				r;
	int				g;
	int				b;
	int				param;
	int				ms;
	double			zoom;
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
int					ft_mouse(int button, int x, int y, t_fractol *f);

#endif
