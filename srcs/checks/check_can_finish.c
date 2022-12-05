/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_can_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:42:53 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 20:26:44 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	VertSearch(int i, int j, char **map, int *flag)
// {
// 	// printf("{%d,%d}\n", i, j);
// 	map[i][j] = '!';
// 	if (map[i + 1][j] == 'E' || map[i - 1][j] == 'E' || map[i][j - 1] == 'E'
// 		|| map[i][j + 1] == 'E')
// 	{
// 		printf("suc\n");
// 		*flag = 1;
// 		return ;
// 	}
// 	if ((map[i][j - 1] == '0' || map[i][j - 1] == 'C') && (map[i][j - 1] == '0'
// 			|| map[i][j - 1] == 'C'))
// 	{
// 		if (*flag == 1)
// 			return ;
// 		VertSearch(i, j - 1, map, flag);
// 	}
// 	if ((map[i - 1][j] == '0' || map[i - 1][j] == 'C') && (map[i - 1][j] == '0'
// 			|| map[i - 1][j] == 'C'))
// 	{
// 		if (*flag == 1)
// 			return ;
// 		VertSearch(i - 1, j, map, flag);
// 	}
// 	if ((map[i][j + 1] == '0' || map[i][j + 1] == 'C') && (map[i][j + 1] == '0'
// 			|| map[i][j + 1] == 'C'))
// 	{
// 		if (*flag == 1)
// 			return ;
// 		VertSearch(i, j + 1, map, flag);
// 	}
// 	if ((map[i + 1][j] == '0' || map[i + 1][j] == 'C') && (map[i + 1][j] == '0'
// 			|| map[i + 1][j] == 'C'))
// 	{
// 		if (*flag == 1)
// 			return ;
// 		VertSearch(i + 1, j, map, flag);
// 	}
// }
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

// void	dfs(t_maps **maps)
// {
// 	int		*flag;
// 	char	**dfs_flag;

// 	flag = (int *)malloc(sizeof(int));
// 	if (!flag)
// 		ft_free_maps(maps, 1);
// 	flag = 0;
// 	ft_dfs_flag_ptr(maps);
// 	if (!dfs_flag)
// 		ft_free_maps(maps, 1);
// 	*flag = 0;
// 	VertSearch((*maps)->player_i, (*maps)->player_j, &(*maps), flag, dfs_flag);
// 	if (*flag == 0)
// 	{
// 		printf("Where is the goal?\n");
// 		ft_free_maps(maps, 1);
// 	}
// 	free(flag);
// }
void	ft_check_can_goal(t_maps **maps)
{
	ft_dfs_flag_ptr(maps);
}
