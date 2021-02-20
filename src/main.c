/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:35:27 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/20 00:22:25 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
		map_create(av[1], fdf);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, fdf->width,
				fdf->height, "F.D.F");
		put_fdf(fdf);
		mlx_key_hook(fdf->win, key_event, (void*)fdf);
		mlx_mouse_hook(fdf->win, mouse_event, (void*)fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_putstr("Usage: ./fdf <file.fdf>\n");
	return (0);
}
