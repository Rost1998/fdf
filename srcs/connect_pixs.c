/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pixs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:44:23 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:45:31 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 0 - delta_x;
** 1 - delta_y;
** 2 - steps_x;
** 3 - steps_y;
** 4 - d;
** 5 - d1;
** 6 - d2;
** 7 - x;
** 8 - y;
*/

static void		case1(t_option *fdf, t_point *point0, double *vars)
{
	int		i;

	vars[4] = vars[1] * 2.0 - vars[0];
	vars[5] = vars[1] * 2.0;
	vars[6] = (vars[1] - vars[0]) * 2.0;
	vars[7] = point0->x + vars[2];
	vars[8] = point0->y;
	i = 1;
	while ((double)i <= vars[0])
	{
		if (vars[4] > 0)
		{
			vars[4] += vars[6];
			vars[8] += vars[3];
		}
		else
			vars[4] += vars[5];
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)vars[7],\
												(int)vars[8], 0xFFFFFF);
		vars[7] += vars[2];
		++i;
	}
}

static void		case2(t_option *fdf, t_point *point0, double *vars)
{
	int		i;

	vars[4] = vars[0] * 2.0 - vars[1];
	vars[5] = vars[0] * 2.0;
	vars[6] = (vars[0] - vars[1]) * 2.0;
	vars[8] = point0->y + vars[3];
	vars[7] = point0->x;
	i = 1;
	while ((double)i <= vars[1])
	{
		if (vars[4] > 0)
		{
			vars[4] += vars[6];
			vars[7] += vars[2];
		}
		else
			vars[4] += vars[5];
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)vars[7],\
												(int)vars[8], 0xFFFFFF);
		vars[8] += vars[3];
		++i;
	}
}

void			connect_pixs(t_option *fdf, t_point *point0, t_point *point1)
{
	double		vars[9];

	vars[0] = ABS(point1->x - point0->x);
	vars[1] = ABS(point1->y - point0->y);
	vars[2] = point1->x >= point0->x ? 1 : -1;
	vars[3] = point1->y >= point0->y ? 1 : -1;
	if (vars[1] <= vars[0])
		case1(fdf, point0, vars);
	else
		case2(fdf, point0, vars);
}
