/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracerot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:43:19 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/19 22:37:07 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		pt_rotz(t_point prf, t_point p, double o_deg)
{
	double	o;
	t_point	ret;

	o = (M_PI / 180.0) * o_deg;
	ret.x = ((p.x - prf.x) * cos(o)) - ((p.y - prf.y) * sin(o)) + prf.x;
	ret.y = ((p.y - prf.y) * cos(o)) + ((p.x - prf.x) * sin(o)) + prf.y;
	return (ret);
}

t_point		pt_roty(t_point prf, t_point p, double o_deg)
{
	double	o;
	t_point ret;

	o = (M_PI / 180.0) * o_deg;
	ret.x = ((p.x - prf.x) * cos(o)) + ((p.z - prf.z) * sin(o)) + prf.x;
	ret.z = ((p.z - prf.z) * cos(o)) - ((p.x - prf.x) * sin(o)) + prf.z;
	return (ret);
}

t_point		pt_rotx(t_point prf, t_point p, double o_deg)
{
	double	o;
	t_point	ret;

	o = (M_PI / 180.0) * o_deg;
	ret.y = ((p.y - prf.y) * cos(o)) + ((p.z - prf.z) * sin(o));
	ret.z = ((p.z - prf.z) * cos(o)) - ((p.y - prf.y) * sin(o));
	return (ret);
}
