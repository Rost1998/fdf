/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:43:24 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/28 18:43:42 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_exit(void *all_data)
{
	ft_memfree_nonvalid_map(*(void**)all_data);
	mlx_clear_window((*((t_option**)all_data + 1))->mlx_ptr,\
									(*((t_option**)all_data + 1))->win_ptr);
	mlx_destroy_window((*((t_option**)all_data + 1))->mlx_ptr,\
									(*((t_option**)all_data + 1))->win_ptr);
	free((void**)all_data);
	exit(1);
	return (0);
}
