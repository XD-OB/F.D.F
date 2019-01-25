/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:06:57 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/20 00:49:53 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 100

# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define BT_R 2
# define K_1 83
# define K_2 84
# define K_MINUS 78
# define K_PLUS 69
# define K_SPACE 49
# define K_C 8
# define K_P 35
# define K_T 17

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_coloralt
{
	int			alt;
	int			color;
	int			r;
	int			g;
	int			b;
}				t_coloralt;

typedef struct	s_map
{
	t_coloralt	**map;
	int			ncolumn;
	int			nline;
	int			x;
	int			y;
	int			error;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_point		p0;
	t_point		p1;
	t_point		p2;
	t_map		map;
	double		step;
	double		depth;
	double		teta;
	int			proj;
	int			color;
	int			width;
	int			height;
}				t_fdf;

int				key_event(int keycode, t_fdf *fdf);
int				mouse_event(int btn, int x, int y, t_fdf *fdf);
void			command_bloc(t_fdf *fdf);
void			ft_xtoi(char *str_hex, t_fdf *fdf);
void			init_color(t_fdf *fdf);
void			init_fdf(t_fdf *fdf);
t_point			point(double x, double y);
void			init_pt(t_point *pt, double x, double y);
void			swap(double *a, double *b);
void			swap_pt(t_point *pt1, t_point *pt2);
t_point			pt_rotx(t_point prf, t_point p, double o_deg);
t_point			pt_roty(t_point prf, t_point p, double o_deg);
t_point			pt_rotz(t_point prf, t_point p, double o_deg);
void			traceline(t_fdf *fdf, t_point pi, t_point pf, int color);
int				get_next_line(const int fd, char **line);
void			tab_alloc(const int fd, char **tab);
void			read_map(const int fd, char **tab);
void			print_tab(t_coloralt **tab, int line, int column);
t_point			rotate(t_point p, int z, int depth);
void			map_create(char *s, t_fdf *fdf);
void			put_fdf(t_fdf *fdf);
void			put_fdf_paral(t_fdf *fdf);
void			set_window(t_fdf *fdf);

#endif
