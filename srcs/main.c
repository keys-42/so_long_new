/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:57:09 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 18:48:41 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;

	ft_new_maps(&maps);
	ft_check(argc, argv, &maps);
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
