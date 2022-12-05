/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:29:50 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 06:09:26 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(t_data **data)
{
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		ft_free_data(data, 1);

}