/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:43:07 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:43:17 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_memfree_for_read(char *line, char **pt)
{
	int		i;

	line ? free(line) : 0;
	i = 0;
	while (pt && pt[i])
		free(pt[i++]);
	pt ? free(pt) : 0;
}

_Bool			ft_memfree_nonvalid_map(t_point **points)
{
	int		i;

	i = 0;
	while (points && points[i])
		free(points[i++]);
	points ? free(points) : 0;
	return (0);
}

_Bool			ft_memfree_all(t_point **points, char *line, char **pt)
{
	ft_memfree_nonvalid_map(points);
	ft_memfree_for_read(line, pt);
	return (0);
}
