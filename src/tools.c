/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 01:59:22 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/19 23:02:44 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_pt(t_point *pt, double x, double y)
{
	pt->x = x;
	pt->y = y;
}

t_point		point(double x, double y)
{
	t_point		p;

	p.x = x;
	p.y = y;
	return (p);
}

void		swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_pt(t_point *pt1, t_point *pt2)
{
	t_point	tmp;

	tmp = *pt1;
	*pt1 = *pt2;
	*pt2 = tmp;
}

void		ft_xtoi(char *str_hex, t_fdf *fdf)
{
	int		hex;

	hex = ft_atoibase(str_hex, "0123456789ABCDEF");
	fdf->map.map[fdf->map.y][fdf->map.x].r = hex >> 16;
	fdf->map.map[fdf->map.y][fdf->map.x].g = (hex >> 8) & 0xFF;
	fdf->map.map[fdf->map.y][fdf->map.x].b = hex & 0xFF;
	fdf->map.map[fdf->map.y][fdf->map.x].color = hex;
}
