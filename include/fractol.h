/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:23:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 17:48:43 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

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
	double			invzoom;
	double			currentzoom;
	double			zr;
	int				r;
	int				g;
	int				b;
	int				change;
	int				max_iter;
	int				move_d;
	int				move_l;
	int				move_r;
	int				move_u;
	int				r_up;
	int				r_down;
	int				g_up;
	int				g_down;
	int				b_up;
	int				b_down;
	int				ms;
	int				param;
	int				pos;
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

typedef struct		s_julia
{
	double			tmp;
	double			refactor;
	double			imfactor;
	double			xmin;
	double			ymin;
}					t_julia;

int					ft_commands(int keycode, t_fractol *f);
int					ft_commands2(int keycode, t_fractol *f);
int					ft_key_down(int keycode, t_fractol *f);
int					ft_key_up(int keycode, t_fractol *f);
int					ft_loop(t_fractol *f);
int					ft_mouse(int button, int x, int y, t_fractol *f);
int					ft_mouse_mvt(int x, int y, t_fractol *f);
int					ft_redcross(t_fractol *f);
void				ft_bs_julia(t_fractol *f);
void				ft_burning_ship(t_fractol *f);
void				ft_julia(t_fractol *f);
void				ft_mandelbrot(t_fractol *f);
void				ft_put_infos(t_fractol *f);
void				ft_switch_colors(int keycode, t_fractol *f);

#endif
