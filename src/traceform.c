/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:57:49 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/19 22:25:58 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		color_lines(t_fdf *fdf, int *flag)
{
	if (fdf->map.map[fdf->map.y][fdf->map.x].color != 0xFFFFFF
			&& *flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->map.map[fdf->map.y]
				[fdf->map.x].color);
	else if (*flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->color);
	fdf->p1 = fdf->p2;
	*flag = 1;
}

static void		color_columns(t_fdf *fdf, int *flag)
{
	if (fdf->map.map[fdf->map.y][fdf->map.x].color != 0xFFFFFF
			&& *flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->map.map[fdf->map.y]
				[fdf->map.x].color);
	else if (*flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->color);
	fdf->p1 = fdf->p2;
	*flag = 1;
}

static void		put_lines(t_fdf *fdf)
{
	t_point		pi;
	int			flag;

	pi = fdf->p0;
	fdf->map.y = -1;
	while (++fdf->map.y < fdf->map.nline)
	{
		flag = 0;
		fdf->map.x = -1;
		fdf->p1 = pi;
		while (++fdf->map.x < fdf->map.ncolumn)
		{
			fdf->p2 = point(pi.x + ((fdf->map.x) * fdf->step), pi.y);
			fdf->p2 = pt_rotz(pi, fdf->p2, fdf->teta);
			fdf->p2.y -= (fdf->map.map[fdf->map.y]
					[fdf->map.x].alt * fdf->depth);
			color_lines(fdf, &flag);
		}
		fdf->p1.x = pi.x - (fdf->step);
		fdf->p1.y = pi.y;
		pi = pt_rotz(pi, fdf->p1, -fdf->teta);
	}
}

static void		put_columns(t_fdf *fdf)
{
	t_point		pi;
	int			flag;

	pi = fdf->p0;
	fdf->map.x = -1;
	while (++fdf->map.x < fdf->map.ncolumn)
	{
		flag = 0;
		fdf->map.y = -1;
		fdf->p1 = pi;
		while (++fdf->map.y < fdf->map.nline)
		{
			fdf->p2 = point(pi.x - (fdf->map.y * fdf->step), pi.y);
			fdf->p2 = pt_rotz(pi, fdf->p2, -fdf->teta);
			fdf->p2.y -= (fdf->map.map[fdf->map.y]
					[fdf->map.x].alt * fdf->depth);
			color_columns(fdf, &flag);
		}
		fdf->p1.x = pi.x + fdf->step;
		fdf->p1.y = pi.y;
		pi = pt_rotz(pi, fdf->p1, fdf->teta);
	}
}

void			put_fdf(t_fdf *fdf)
{
	put_lines(fdf);
	put_columns(fdf);
	command_bloc(fdf);
}
