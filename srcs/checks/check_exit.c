/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:22:17 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 14:52:47 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_exit_position(char *line, t_maps **maps, int *flag)
{
	int	i;
	int	ans;

	ans = 0;
	i = 0;
	while (1)
	{
		if (!line[i])
			break ;
		else
		{
			if (line[i] == 'E')
			{
				(*maps)->exit_j = i;
				*flag = 1;
				ans++;
			}
		}
		i++;
	}
	return (ans);
}

void	ft_check_exit(t_maps **maps)
{
	int	head;
	int	tail;
	int	num;
	int	flag;

	flag = 0;
	head = (*maps)->wall_head;
	tail = (*maps)->wall_tail;
	num = 0;
	while (head <= tail)
	{
		if (flag == 0)
			(*maps)->exit_i = head;
		num += ft_exit_position((*maps)->map[head], maps, &flag);
		head++;
	}
	if (num < 1 || 2 <= num)
	{
		printf("exit num =%d\n", num);
		ft_free_maps(maps, 1);
	}
}
