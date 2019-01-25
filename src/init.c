/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 04:24:04 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/20 00:01:13 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->step = 35;
	fdf->depth = 1;
	fdf->p0 = point(0.35 * fdf->width, 0.1 * fdf->height);
	fdf->teta = 30;
	fdf->color = 0xFFFFFF;
	fdf->proj = 0;
}

void	init_color(t_fdf *fdf)
{
	fdf->map.map[fdf->map.y][fdf->map.x].r = 255;
	fdf->map.map[fdf->map.y][fdf->map.x].g = 255;
	fdf->map.map[fdf->map.y][fdf->map.x].b = 255;
	fdf->map.map[fdf->map.y][fdf->map.x].color = fdf->color;
}
