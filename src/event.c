/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:28:38 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/20 00:27:39 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		switch_proj(t_fdf *fdf)
{
	if (fdf->proj == 0)
		fdf->proj = 1;
	else
		fdf->proj = 0;
}

static void		projection(t_fdf *fdf)
{
	if (fdf->proj == 0)
		put_fdf(fdf);
	else
		put_fdf_paral(fdf);
}

static void		event(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
		exit(1);
	else if (keycode == K_1 && fdf->step > 10)
		fdf->step -= 10;
	else if (keycode == K_2)
		fdf->step += 10;
	else if (keycode == K_DOWN)
		fdf->p0.y += 50;
	else if (keycode == K_UP)
		fdf->p0.y -= 50;
	else if (keycode == K_RIGHT)
		fdf->p0.x += 50;
	else if (keycode == K_LEFT)
		fdf->p0.x -= 50;
	else if (keycode == K_MINUS)
		fdf->depth--;
	else if (keycode == K_PLUS)
		fdf->depth++;
	else if (keycode == K_C)
		fdf->teta += 20;
}

int				key_event(int keycode, t_fdf *fdf)
{
	event(keycode, fdf);
	if (keycode == K_T)
		fdf->teta = 26.57;
	if (keycode == K_P)
		switch_proj(fdf);
	else if (keycode == 0)
		fdf->color -= 3;
	else if (keycode == K_SPACE)
		init_fdf(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	projection(fdf);
	return (1);
}

int				mouse_event(int btn, int x, int y, t_fdf *fdf)
{
	if (y > 30 && y < (fdf->height - 30) && btn == 1)
		fdf->p0 = point(x, y);
	if (y > 0 && y < 22 && btn == 1)
	{
		if (x > fdf->width - 22 && x < fdf->width - 2)
			fdf->color = 0xFF0000;
		if (x > fdf->width - 44 && x < fdf->width - 24)
			fdf->color = 0xFFCC00;
		if (x > fdf->width - 66 && x < fdf->width - 46)
			fdf->color = 0x00CCFF;
		if (x > fdf->width - 88 && x < fdf->width - 68)
			fdf->color = 0x40FF00;
		if (x > fdf->width - 110 && x < fdf->width - 90)
			fdf->color = 0xFF66CC;
		if (x > fdf->width - 132 && x < fdf->width - 112)
			fdf->color = 0xCC66FF;
		if (x > fdf->width - 154 && x < fdf->width - 134)
			fdf->color = 0x00FFCC;
		if (x > fdf->width - 172 && x < fdf->width - 156)
			fdf->color = 0x669999;
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	projection(fdf);
	return (1);
}
