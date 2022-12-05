/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_can_goal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:42:53 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 04:10:07 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_check_space(int i, int j, char **map, t_maps **maps, int *flag)
{
	if (map[i][j] == 'E')
	{
		*flag = 1;
		return (true);
	}
	if (map[i][j] == '0')
		return (true);
	else if (map[i][j] == 'C')
	{
		(*maps)->collection_num = 1;
		return (true);
	}
	return (false);
}

static void	VertSearch(int i, int j, char **map, int *flag, t_maps **maps)
{
	map[i][j] = '!';
	if (ft_check_space(i, j - 1, map, maps, flag))
		VertSearch(i, j - 1, map, flag, maps);
	if (ft_check_space(i - 1, j, map, maps, flag))
		VertSearch(i - 1, j, map, flag, maps);
	if (ft_check_space(i, j + 1, map, maps, flag))
		VertSearch(i, j + 1, map, flag, maps);
	if (ft_check_space(i + 1, j, map, maps, flag))
		VertSearch(i + 1, j, map, flag, maps);
}

void	ft_map_copy(t_maps **maps, char **flag)
{
	int	head;
	int	hight;
	int	i;

	i = 0;
	hight = (*maps)->hight;
	head = (*maps)->wall_head;
	while (i < hight)
	{
		flag[i] = ft_strdup((*maps)->map[head]);
		if (!flag[i])
			ft_free_maps(maps, 1);
		i++;
		head++;
	}
	flag[i] = NULL;
}

void	ft_dfs_flag_ptr(t_maps **maps)
{
	char	**flag;

	flag = (char **)malloc(sizeof(char *) * ((*maps)->hight + 1));
	if (!flag)
		ft_free_maps(maps, 1);
	(*maps)->dfs_flag = flag;
	ft_map_copy(maps, flag);
}

void	ft_check_can_goal(t_maps **maps)
{
	int	*flag;

	ft_dfs_flag_ptr(maps);
	flag = (int *)malloc(sizeof(int));
	if (!flag)
		ft_free_maps(maps, 1);
	*flag = 0;
	(*maps)->collection_num = 0;
	VertSearch((*maps)->player_i, (*maps)->player_j, (*maps)->dfs_flag, flag,
			maps);
	if (*flag == 0 || (*maps)->collection_num <= 0)
	{
		printf("no_goal\n");
		free(flag);
		ft_free_maps(maps, 1);
	}
	free(flag);
}
