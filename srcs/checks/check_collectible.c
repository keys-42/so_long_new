/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:36:38 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 19:40:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_collectible_check(char *line)
{
	int	i;
	int	ans;

	ans = 0;
	i = 1;
	while (1)
	{
		if (line[i + 1] == '\n')
			break ;
		else
		{
			if (line[i] == 'C')
				ans++;
		}
		i++;
	}
	return (ans);
}

void	ft_check_collectible(t_maps **maps)
{
	int	head;
	int	tail;
	int	num;

	head = (*maps)->wall_head;
	tail = (*maps)->wall_tail;
	num = 0;
	while (head <= tail)
	{
		num += ft_collectible_check((*maps)->map[head]);
		head++;
	}
	if (num < 1)
	{
		printf("collectible\n");
		ft_free_maps(maps, 1);
	}
	else
		(*maps)->collection_num = num;
}
