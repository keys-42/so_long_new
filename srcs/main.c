/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:57:09 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 15:55:07 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_data	*data;
	ft_new_maps(&maps);
	ft_check(argc, argv, &maps);
	ft_new_data(&data,&maps);
	ft_mlx_make(&data);
	ft_free_data(&data,1);
	// ft_free_maps(&maps,1);
	return (0);
}


// 		int i = 0;
// while((data)->maps->map[i])
// {
// 		printf("%s\n",(data)->maps->map[i]);
// 	i++;
// }
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
