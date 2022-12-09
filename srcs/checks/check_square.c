/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:45:05 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 20:33:04 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_square(t_maps **maps)
{
	size_t	len1;
	size_t	len2;
	int		head;
	int		tail;

	head = (*maps)->wall_head;
	tail = (*maps)->wall_tail;
	printf("%d %d",head,tail);
	if ((tail - head) < 2)
	{
		printf("Not_square_tree\n");
		ft_free_maps(maps, 1);
	}
	len1 = ft_strlen((*maps)->map[head]);
	while (head <= tail)
	{
		len2 = ft_strlen((*maps)->map[head]);
		if (len1 != len2)
		{
			printf("Not_square\n");
			ft_free_maps(maps, 1);
		}
		head++;
	}
	(*maps)->width = (int)len1;
	(*maps)->hight = (*maps)->wall_tail - (*maps)->wall_head + 1;
}
