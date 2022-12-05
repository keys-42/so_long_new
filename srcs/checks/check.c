/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:32:03 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 04:06:16 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_filename_check(char *filename, t_maps **maps)
{
	size_t	i;

	i = ft_strlen(filename);
	if (4 <= i)
	{
		if (ft_strncmp(&filename[i - 4], ".ber", 4) == 0)
			return ;
		else
		{
			printf("Filename is different.\n");
			ft_free_maps(maps, 1);
			exit(1);
		}
	}
	else
	{
		printf("Filename is different.\n");
		ft_free_maps(maps, 1);
		exit(1);
	}
}

void	ft_check(int argc, char **argv, t_maps **maps)
{
	if (argc != 2)
		free(*maps);
	else
	{
		ft_filename_check(argv[1], maps);
		ft_make_map(argv[1], maps);
		ft_check_wall(maps);
		ft_check_square(maps);
		ft_check_player(maps);
		ft_check_exit(maps);
		ft_check_collectible(maps);
		ft_useless_characters(maps);
		ft_check_can_goal(maps);

		////////////////////////////////////////////////////////////////////////////
		int i = 0;
		int j;
		while ((*maps)->map[i])
		{
			j = 0;
			while ((*maps)->map[i][j])
			{
				printf("%c", (*maps)->map[i][j]);
				j++;
			}
			i++;
		}
		printf("fd = %d\n", (*maps)->fd);
		printf("hight = %d\n", (*maps)->hight);
		printf("width = %d\n", (*maps)->width);
		printf("wall_head = %d\n", (*maps)->wall_head);
		printf("wall_tail = %d\n", (*maps)->wall_tail);
		printf("player_i = %d\n", (*maps)->player_i);
		printf("player_j = %d\n", (*maps)->player_j);
		printf("exit_i = %d\n", (*maps)->exit_i);
		printf("exit_j = %d\n", (*maps)->exit_j);
		printf("collection_num = %d\n", (*maps)->collection_num);
		 i = 0;
		while ((*maps)->dfs_flag[i])
		{
			j = 0;
			while ((*maps)->dfs_flag[i][j])
			{
				printf("%c", (*maps)->dfs_flag[i][j]);
				j++;
			}
			i++;
		}
		////////////////////////////////////////////////////////////////////////////
		// int i = 0;
		// int j;
		// while ((*maps)->map[i])
		// {
		// 	j = 0;
		// 	while ((*maps)->map[i][j])
		// 	{
		// 		printf("%c", (*maps)->map[i][j]);
		// 		j++;
		// 	}
		// 	i++;
		// }
		// printf("fd = %d\n", (*maps)->fd);
		// printf("hight = %d\n", (*maps)->hight);
		// printf("width = %d\n", (*maps)->width);
		// printf("wall_head = %d\n", (*maps)->wall_head);
		// printf("wall_tail = %d\n", (*maps)->wall_tail);
		// printf("player_i = %d\n", (*maps)->player_i);
		// printf("player_j = %d\n", (*maps)->player_j);
		// printf("exit_i = %d\n", (*maps)->exit_i);
		// printf("exit_j = %d\n", (*maps)->exit_j);
		// printf("collection_num = %d\n", (*maps)->collection_num);
		ft_free_maps(maps, 1);
	}
}
