/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:42:45 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:42:59 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		minmax_z(t_option *fdf, t_point **points)
{
	int		i;
	double	z_min;
	double	z_max;

	i = 0;
	z_min = 0.0 / 0.0;
	z_max = 0.0 / 0.0;
	while (points[i])
	{
		if ((points[i])->z < z_min || z_min != z_min)
			z_min = (points[i])->z;
		if ((points[i])->z > z_max || z_max != z_max)
			z_max = (points[i])->z;
		++i;
	}
	fdf->z_max = z_max;
	fdf->z_min = z_min;
}

static void		wh(t_option *fdf, t_point **points)
{
	int		i;

	i = 0;
	while (points[i] && !((points[i])->y))
		i++;
	fdf->width = i;
	fdf->height = ft_adrlen((void**)points) / i;
}

void			fill_struct(t_option *fdf, t_point **points)
{
	fdf->scale = 33;
	fdf->offset_x = WINDOW_WIDTH / 2;
	fdf->offset_y = WINDOW_HEIGHT / 2;
	fdf->cam_x = CAM_X;
	fdf->cam_y = CAM_Y;
	fdf->cam_z = CAM_Z;
	minmax_z(fdf, points);
	wh(fdf, points);
}
