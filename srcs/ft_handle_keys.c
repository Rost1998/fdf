/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:44:10 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 23:07:36 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_ret_coord(t_point **points)
{
	int		i;

	i = 0;
	while (points[i])
	{
		(points[i])->x = (points[i])->old_x;
		(points[i])->y = (points[i])->old_y;
		(points[i])->z = (points[i])->old_z;
		++i;
	}
}

static void		ft_rerotate(void *all_data)
{
	mlx_clear_window((*((t_option**)all_data + 1))->mlx_ptr,\
									(*((t_option**)all_data + 1))->win_ptr);
	ft_ret_coord(*(t_point***)all_data);
	upgrade_points(*(void**)all_data, *((void**)all_data + 1));
	get_connection(*(void**)all_data, *((void**)all_data + 1));
}

int				ft_handle_keys(int key, void *all_data)
{
	if (key == 53)
		ft_exit(all_data);
	key == 125 ? (*((t_option**)all_data + 1))->cam_x += 0.2 : 0;
	key == 126 ? (*((t_option**)all_data + 1))->cam_x -= 0.2 : 0;
	key == 124 ? (*((t_option**)all_data + 1))->cam_z -= 0.2 : 0;
	key == 123 ? (*((t_option**)all_data + 1))->cam_z += 0.2 : 0;
	key == 69 ? (*((t_option**)all_data + 1))->scale += 2 : 0;
	key == 78 ? (*((t_option**)all_data + 1))->scale -= 2 : 0;
	ft_rerotate(all_data);
	return (0);
}
