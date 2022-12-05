/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:25:16 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 05:36:03 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_maps(t_maps **maps)
{
	*maps = (t_maps *)malloc(sizeof(t_maps));
	if (!maps)
		exit(EXIT_FAILURE);
	(*maps)->map = NULL;
	(*maps)->dfs_flag = NULL;
	(*maps)->fd = -1;
	(*maps)->hight = -1;
	(*maps)->width = -1;
	(*maps)->wall_head = -1;
	(*maps)->wall_tail = -1;
	(*maps)->player_i = -1;
	(*maps)->player_j = -1;
	(*maps)->exit_i = -1;
	(*maps)->exit_j = -1;
	(*maps)->collection_num = -1;
	(*maps)->flag = 0;
}

void	ft_new_data(t_data **data, t_maps **maps)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_free_maps(maps, 1);
	(*data)->maps = *maps;
}
