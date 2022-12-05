/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_can_goal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:42:53 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 04:20:54 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_check_space(int i, int j, char **map, t_maps **maps)
{
	if (map[i][j] == 'E')
	{
		(*maps)->flag = 1;
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

static void	ft_goal_search(int i, int j, char **map, t_maps **maps)
{
	map[i][j] = '!';
	if (ft_check_space(i, j - 1, map, maps))
		ft_goal_search(i, j - 1, map, maps);
	if (ft_check_space(i - 1, j, map, maps))
		ft_goal_search(i - 1, j, map, maps);
	if (ft_check_space(i, j + 1, map, maps))
		ft_goal_search(i, j + 1, map, maps);
	if (ft_check_space(i + 1, j, map, maps))
		ft_goal_search(i + 1, j, map, maps);
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
	int	i;
	int	j;

	i = (*maps)->player_i;
	j = (*maps)->player_j;
	ft_dfs_flag_ptr(maps);
	(*maps)->collection_num = 0;
	ft_goal_search(i, j, (*maps)->dfs_flag, maps);
	if ((*maps)->flag == 0 || (*maps)->collection_num <= 0)
	{
		printf("no_goal\n");
		ft_free_maps(maps, 1);
	}
}
