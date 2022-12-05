/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:13:18 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 19:24:39 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_player_search(char *line, t_maps **maps)
{
	int	i;
	int	ans;

	ans = 0;
	i = 0;
	while (1)
	{
		if (!line[i])
			break ;
		if (line[i] == 'P')
		{
			(*maps)->player_j = i;
			ans++;
		}
		i++;
	}
	return (ans);
}

void	ft_check_player(t_maps **maps)
{
	int	head;
	int	tail;
	int	num;
	int	flag;

	head = (*maps)->wall_head;
	tail = (*maps)->wall_tail;
	flag = 0;
	num = 0;
	while (head <= tail)
	{
		num += ft_player_search((*maps)->map[head], maps);
		if (num > 0 && flag == 0)
		{
			(*maps)->player_i = head;
			flag = 1;
		}
		head++;
	}
	if (num < 1 || 2 <= num)
	{
		printf("player\n");
		ft_free_maps(maps, 1);
	}
}
