/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:15:37 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:42:36 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_pixels(t_point **points, void *init, void *window)
{
	int		i;

	i = 0;
	while (points[i])
	{
		mlx_pixel_put(init, window, (points[i])->x, (points[i])->y, 0xFFFFFF);
		++i;
	}
}

void			get_connection(t_point **points, t_option *fdf)
{
	int		i;
	int		len;

	len = fdf->width;
	i = 0;
	while (points[i])
	{
		if (i % len)
			connect_pixs(fdf, points[i], points[i - 1]);
		if (i >= len)
			connect_pixs(fdf, points[i], points[i - len]);
		++i;
	}
}

int				main(int argc, char **argv)
{
	void		*all_data;
	t_option	fdf;
	t_point		**points;

	if (argc != 2)
		return (0);
	if (!(all_data = ft_memalloc(sizeof(void*) * 2)))
		return (0);
	if (!(points = read_file(argv[1])))
		return (0);
	*(void**)all_data = points;
	*((void**)all_data + 1) = &fdf;
	fill_struct(&fdf, points);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,\
																	"FdF");
	upgrade_points(points, &fdf);
	put_pixels(points, fdf.mlx_ptr, fdf.win_ptr);
	get_connection(points, &fdf);
	mlx_hook(fdf.win_ptr, 2, 5, ft_handle_keys, all_data);
	mlx_hook(fdf.win_ptr, 17, 5, ft_exit, all_data);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
