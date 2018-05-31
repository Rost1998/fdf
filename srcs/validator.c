/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:40:35 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:40:42 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

_Bool		ft_isvalid(char **points)
{
	static size_t	len;
	char			*tmp;
	int				i;

	i = 0;
	!len ? (len = ft_adrlen((void**)points)) : 0;
	if (ft_adrlen((void**)points) != len)
		return (0);
	while (points[i])
	{
		if ((tmp = ft_memchr(points[i], ',', ft_strlen(points[i]))))
			*tmp = 0;
		if (!ft_isnumber(points[i]))
			return (0);
		++i;
	}
	return (1);
}
