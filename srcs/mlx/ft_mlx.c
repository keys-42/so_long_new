/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:29:50 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 17:10:05 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_image_init(t_data **data)
{
	int	hight;
	int	width;

	hight = WINDOWSIZE;
	width = WINDOWSIZE;
	(*data)->wall_image = mlx_xpm_file_to_image((*data)->mlx,
												"./images/wall-_1_.xpm",
												&hight,
												&width);
	(*data)->space_image = mlx_xpm_file_to_image((*data)->mlx,
													"./images/white-_1_.xpm",
													&hight,
													&width);
	(*data)->player_image = mlx_xpm_file_to_image((*data)->mlx,
													"./images/sanji.xpm",
													&hight,
													&width);
	(*data)->collection_image = mlx_xpm_file_to_image((*data)->mlx,
														"./images/chopper.xpm",
														&hight,
														&width);
	(*data)->exit_image = mlx_xpm_file_to_image((*data)->mlx,
												"./images/nami.xpm",
												&hight,
												&width);
}

static void	put_inside_map_utils(t_data **data, const char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window((*data)->mlx, (*data)->mlx_win,
				(*data)->space_image, WINDOWSIZE * i, WINDOWSIZE * j);
	if (c == '1')
		mlx_put_image_to_window((*data)->mlx, (*data)->mlx_win,
				(*data)->wall_image, WINDOWSIZE * i, WINDOWSIZE * j);
	if (c == 'P')
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->mlx_win,
				(*data)->player_image, WINDOWSIZE * i, WINDOWSIZE * j);
		(*data)->maps->player_i = i;
		(*data)->maps->player_j = j;
	}
	if (c == 'E')
		mlx_put_image_to_window((*data)->mlx, (*data)->mlx_win,
				(*data)->exit_image, WINDOWSIZE * i, WINDOWSIZE * j);
	if (c == 'C')
		mlx_put_image_to_window((*data)->mlx, (*data)->mlx_win,
				(*data)->collection_image, WINDOWSIZE * i, WINDOWSIZE * j);
}

static int	put_inside_map(t_data **data)
{
	int	head;
	int	tail;
	int	i;
	int j;

	j = 0;
	head = (*data)->maps->wall_head;
	tail = (*data)->maps->wall_tail;
	while (head <= tail)
	{
		i=0;
		while ((*data)->maps->map[head][i])
		{
			put_inside_map_utils(data, (*data)->maps->map[head][i], i,j);
			i++;
		}
		head++;
		j++;
	}
	return (0);
}

void	ft_mlx_make(t_data **data)
{
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		ft_free_data(data, 1);
	(*data)->mlx_win = mlx_new_window((*data)->mlx, WINDOWSIZE
			* ((*data)->maps->width), WINDOWSIZE * ((*data)->maps->hight),
			"so_long");
	mlx_image_init(data);
	mlx_loop_hook((*data)->mlx, put_inside_map, data);
	// mlx_hook((*data)->mlx_win, 2, 1L << 0, move_maps, (*data));
	// mlx_hook((*data)->mlx_win, 17, 1L << 2, destroy_mlx, (*data));
	mlx_loop((*data)->mlx);
}
