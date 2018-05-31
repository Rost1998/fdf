/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade_pixs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:41:01 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:41:51 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_rotate_around_x(t_point *point, t_option *fdf)
{
	double		tmp_y;
	double		tmp_z;

	tmp_y = point->y;
	tmp_z = point->z;
	point->y = tmp_y * cos(fdf->cam_x) + tmp_z * sin(fdf->cam_x);
	point->z = -tmp_y * sin(fdf->cam_x) + tmp_z * cos(fdf->cam_x);
}

static void		ft_rotate_around_y(t_point *point, t_option *fdf)
{
	double		tmp_x;
	double		tmp_z;

	tmp_x = point->x;
	tmp_z = point->z;
	point->x = tmp_x * cos(fdf->cam_y) - tmp_z * sin(fdf->cam_y);
	point->z = tmp_x * sin(fdf->cam_y) + tmp_z * cos(fdf->cam_y);
}

static void		ft_rotate_around_z(t_point *point, t_option *fdf)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = point->x;
	tmp_y = point->y;
	point->x = tmp_x * cos(fdf->cam_z) + tmp_y * sin(fdf->cam_z);
	point->y = -tmp_x * sin(fdf->cam_z) + tmp_y * cos(fdf->cam_z);
}

static void		ft_rotate(t_point *point, t_option *fdf)
{
	ft_rotate_around_x(point, fdf);
	ft_rotate_around_y(point, fdf);
	ft_rotate_around_z(point, fdf);
}

void			upgrade_points(t_point **points, t_option *fdf)
{
	int		i;

	i = 0;
	while (points[i])
	{
		(points[i])->x -= (fdf->width - 1) / 2.0;
		(points[i])->y -= (fdf->height - 1) / 2.0;
		if (fdf->z_max != fdf->z_min)
			(points[i])->z /= ((fdf->z_max - fdf->z_min) * SENSE_Z);
		else
			(points[i])->z = 0.0;
		ft_rotate(points[i], fdf);
		(points[i])->x *= fdf->scale;
		(points[i])->y *= fdf->scale;
		(points[i])->x += fdf->offset_x;
		(points[i])->y += fdf->offset_y;
		++i;
	}
}
