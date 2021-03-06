/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:38:17 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:38:18 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

_Bool		ft_isnumber(char *num)
{
	int		i;

	if (*num == '-' || *num == '+')
		++num;
	i = 0;
	while (num[i] && ft_isdigit(num[i]))
		++i;
	return (num[i] ? 0 : 1);
}
