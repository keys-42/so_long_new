/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:56:49 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 14:47:13 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_side_wall_check(char *line, t_maps **maps)
{
	int	i;

	i = 0;
	if (line[0] != '1')
	{
		printf("side_wall\n");
		ft_free_maps(maps, 1);
	}
	while (line[i])
		i++;
	if (line[i - 1] != '1')
	{
		printf("side_wall\n");
		ft_free_maps(maps, 1);
	}
}

static void	ft_upper_lower_wall_check(char *line, int flag, t_maps **maps)
{
	int	i;

	i = 0;
	while (!line[i])
	{
		if (line[i] != '1')
		{
			if (flag == 1)
			{
				printf("upper_wall\n");
				ft_free_maps(maps, 1);
			}
			else
			{
				printf("lower_wall\n");
				ft_free_maps(maps, 1);
			}
		}
		i++;
	}
}

void	ft_check_wall(t_maps **maps)
{
	int	i;

	i = 0;
	while ((*maps)->map[i])
	{
		if (i == 0)
		{
			while (ft_isspace((*maps)->map[i][0]))
				i++;
			(*maps)->wall_head = i;
			if ((*maps)->map[i])
				ft_upper_lower_wall_check((*maps)->map[i], 1, maps);
		}
		else if ((*maps)->map[i + 1] == NULL || (*maps)->map[i + 1][0] == '\n')
		{
			ft_upper_lower_wall_check((*maps)->map[i], 2, maps);
			(*maps)->wall_tail = i;
			return ;
		}
		else
		{
			ft_side_wall_check((*maps)->map[i], maps);
		}
		i++;
	}
}
