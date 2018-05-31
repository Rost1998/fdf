/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:39:02 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:40:21 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static _Bool		ft_write_coords_of_points(t_point ***points,\
										char **points_tmp, int iteration)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = ft_adrlen((void**)points_tmp);
	len = ft_adrlen((void**)(*points));
	while (i < j)
	{
		if (!(*points = (t_point**)ft_realloc_modf(*points,
				sizeof(t_point*) * (len + 2), sizeof(t_point*) * len)))
			return (0);
		if (!((*points)[len] = ft_new_node()))
			return (0);
		((*points)[len])->y = (double)iteration;
		((*points)[len])->x = (double)i;
		((*points)[len])->z = (double)ft_atoi(points_tmp[i]);
		((*points)[len])->old_y = (double)iteration;
		((*points)[len])->old_x = (double)i;
		((*points)[len])->old_z = (double)ft_atoi(points_tmp[i]);
		++len;
		++i;
	}
	return (1);
}

static t_point		**read_lines(int fd)
{
	t_point		**points;
	char		*line;
	char		**points_tmp;
	int			num_p;
	int			iteration;

	iteration = 0;
	points = 0;
	num_p = 0;
	while (get_next_line(fd, &line) > 0)
	{
		points_tmp = ft_strsplit(line, ' ');
		num_p += ft_adrlen((void**)points_tmp);
		if (!ft_isvalid(points_tmp))
			return ((t_point**)ft_memfree_all(points, line, points_tmp));
		if (!(ft_write_coords_of_points(&points, points_tmp, iteration)))
			return ((t_point**)ft_memfree_all(points, line, points_tmp));
		ft_memfree_for_read(line, points_tmp);
		++iteration;
	}
	return (points);
}

t_point				**read_file(char *file)
{
	t_point		**points;
	int			fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	if (!(points = read_lines(fd)))
		return (0);
	return (points);
}
