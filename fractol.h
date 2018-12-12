/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:23:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 16:14:57 by vrenaudi         ###   ########.fr       */
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
	char			*strima;
	double			ci;
	double			cr;
	double			xmax;
	double			xmin;
	double			ymax;
	double			ymin;
	double			zi;
	double			zoom;
	double			zr;
	int				b;
	int				change;
	int				g;
	int				max_iter;
	int				move_d;
	int				move_l;
	int				move_r;
	int				move_u;
	int				ms;
	int				param;
	int				pos;
	int				r;
	int				trigger;
	void			*mlxima;
	void			*mlxptr;
	void			*mlxwin;
}					t_fractol;

typedef struct		s_tab
{
	int				x;
	int				y;
}					t_tab;

int					ft_commands(int keycode, t_fractol *f);
int					ft_commands2(int keycode, t_fractol *f);
int					ft_key_down(int keycode, t_fractol *f);
int					ft_key_up(int keycode, t_fractol *f);
int					ft_loop(t_fractol *f);
int					ft_mouse(int button, int x, int y, t_fractol *f);
int					ft_mouse_mvt(int x, int y, t_fractol *f);
void				ft_julia(t_fractol *f);
void				ft_mandelbrot(t_fractol *f);

#endif
