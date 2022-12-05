/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:32:03 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 04:24:50 by keys             ###   ########.fr       */
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
	}
}
