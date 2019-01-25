/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:22:12 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/18 23:11:25 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		e_modif(double *e, t_point *delta, t_point *pt, int flag)
{
	if (flag == 1 || flag == -1)
	{
		*e += delta->x;
		pt->y += flag;
	}
	if (flag == 0)
	{
		*e += delta->y;
		pt->x++;
	}
}

static void		tracepdy(t_fdf *fdf, t_point pi, t_point pf, int color)
{
	t_point		delta;
	double		e;

	delta.x = pf.x - pi.x;
	delta.y = fabs(pf.y - pi.y);
	if (delta.x > delta.y)
	{
		e = delta.x / 2;
		while (pi.x < pf.x)
		{
			if ((e -= delta.y) < 0)
				e_modif(&e, &delta, &pi, 1);
			mlx_pixel_put(fdf->mlx, fdf->win, pi.x++, pi.y, color);
		}
		return ;
	}
	e = delta.y / 2;
	while (pi.y < pf.y)
	{
		if ((e -= delta.x) < 0)
			e_modif(&e, &delta, &pi, 0);
		mlx_pixel_put(fdf->mlx, fdf->win, pi.x, pi.y++, color);
	}
}

static void		tracemdy(t_fdf *fdf, t_point pi, t_point pf, int color)
{
	t_point		delta;
	double		e;

	delta.x = pf.x - pi.x;
	delta.y = fabs(pf.y - pi.y);
	if (delta.x > delta.y)
	{
		e = delta.x / 2;
		while (pi.x < pf.x)
		{
			if ((e -= delta.y) < 0)
				e_modif(&e, &delta, &pi, -1);
			mlx_pixel_put(fdf->mlx, fdf->win, pi.x++, pi.y, color);
		}
		return ;
	}
	e = delta.y / 2;
	while (pi.y > pf.y)
	{
		if ((e -= delta.x) < 0)
			e_modif(&e, &delta, &pi, 0);
		mlx_pixel_put(fdf->mlx, fdf->win, pi.x, pi.y--, color);
	}
}

void			traceline(t_fdf *fdf, t_point pi, t_point pf, int color)
{
	t_point		delta;
	double		e;

	if (pi.x > pf.x)
		swap_pt(&pi, &pf);
	delta.x = pf.x - pi.x;
	delta.y = pf.y - pi.y;
	mlx_pixel_put(fdf->mlx, fdf->win, pi.x, pi.y, color);
	if (delta.y > 0)
		tracepdy(fdf, pi, pf, color);
	else
		tracemdy(fdf, pi, pf, color);
	mlx_pixel_put(fdf->mlx, fdf->win, pf.x, pf.y, color);
}
