/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:44:02 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:44:02 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_new_node(void)
{
	t_point		*new;

	if (!(new = (t_point*)ft_memalloc(sizeof(t_point))))
		return (0);
	new->x = 0.0;
	new->y = 0.0;
	new->z = 0.0;
	new->color = 0;
	return (new);
}
