/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:57:09 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 20:37:10 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_data	*data;

	ft_new_maps(&maps);
	ft_check(argc, argv, &maps);
	ft_new_data(&data, &maps);
	printf("player_i%d\n", (data)->maps->player_i);
	printf("player_i%d\n", (data)->maps->player_j);
	ft_mlx_make(&data);
	// int		i;
	// i = 0;
	// while ((data)->maps->map[i])
	// {
	// 	printf("%s\n", (data)->maps->map[i]);
	// 	i++;
	// }
	ft_free_data(&data, 1);
	// ft_free_maps(&maps,1);
	return (0);
}

// int i = 0;
// int j;
// while((*maps)->map[i])
// {
// 	j = 0;
// 	while((*maps)->map[i][j])
// 	{
// 		printf("%c",(*maps)->map[i][j]);
// 		j++;
// 	}
// 	i++;
// }
