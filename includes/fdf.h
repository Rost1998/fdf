/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:13:44 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/03/11 17:26:29 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024

# define SENSE_Z 0.25
# define CAM_X -0.4
# define CAM_Y -0.4
# define CAM_Z 0.0

# define ABS(x) ((x) > 0 ? (x) : -(x))

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct	s_option
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	double		z_min;
	double		z_max;
	double		offset_x;
	double		offset_y;
	double		cam_x;
	double		cam_y;
	double		cam_z;
	int			scale;
}				t_option;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	double		old_x;
	double		old_y;
	double		old_z;
	int			color;
}				t_point;

t_point			**read_file(char *file);
t_point			*ft_new_node(void);
_Bool			ft_isvalid(char **points);
void			fill_struct(t_option *fdf, t_point **points);
void			upgrade_points(t_point **points, t_option *fdf);
void			connect_pixs(t_option *fdf, t_point *point0, t_point *point1);
void			get_connection(t_point **points, t_option *fdf);
int				ft_handle_keys(int key, void *all_data);
_Bool			ft_memfree_all(t_point **points, char *line, char **pt);
_Bool			ft_memfree_nonvalid_map(t_point **points);
void			ft_memfree_for_read(char *line, char **pt);
int				ft_exit(void *all_data);

#endif
