/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 05:29:50 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 19:26:27 by keys             ###   ########.fr       */
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
	int	j;

	j = 0;
	head = (*data)->maps->wall_head;
	tail = (*data)->maps->wall_tail;
	while (head <= tail)
	{
		i = 0;
		while ((*data)->maps->map[head][i])
		{
			put_inside_map_utils(data, (*data)->maps->map[head][i], i, j);
			i++;
		}
		head++;
		j++;
	}
	return (0);
}

int	ft_close(int key_num, t_data **data)
{
	// printf("keynum=%d\n",key_num);
	if (key_num == ESC_KEY)
	{
		mlx_destroy_image((*data)->mlx, (*data)->wall_image);
		mlx_destroy_image((*data)->mlx, (*data)->space_image);
		mlx_destroy_image((*data)->mlx, (*data)->player_image);
		mlx_destroy_image((*data)->mlx, (*data)->exit_image);
		mlx_destroy_image((*data)->mlx, (*data)->collection_image);
		ft_free_data(data, 1);
	}
	return (0);
}

void	ft_swap(char *x, char *y, int flag)
{
	char	tmp;

	if (flag == 1)
		*y = '0';
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_map_swap(t_data **data, int x, int y)
{
	int	i;
	int	j;
	int	flag;

	j = (*data)->maps->player_j;
	i = (*data)->maps->player_i;

	if ((*data)->maps->map[j + x][i + y] != '1')
	{
		if ((*data)->maps->map[j + x][i + y] == 'E')
			ft_close(ESC_KEY, data);
		if ((*data)->maps->map[j + x][i + y] == '0')
			flag = 0;
		if ((*data)->maps->map[j + x][i + y] == 'C')
			flag = 1;
		ft_swap(&((*data)->maps->map[j][i]), &((*data)->maps->map[j + x][i
					+ y]), flag);
		(*data)->maps->player_i += x;
		(*data)->maps->player_j += y;
	}
}

int	ft_remake_map(int key_num, t_data **data)
{
	printf("keynum=%d\n", key_num);
	if (key_num == ESC_KEY)
	{
		write(1, "ESC\n", 4);
		ft_close(ESC_KEY, data);
	}
	if (key_num == UP_KEY)
	{
		write(1, "upp\n", 4);
		ft_map_swap(data, -1, 0);
	}
	if (key_num == RIGHT_KEY)
	{
		write(1, "rig\n", 4);
		ft_map_swap(data, 0, 1);
	}
	if (key_num == LEFT_KEY)
	{
		write(1, "lef\n", 4);
		ft_map_swap(data, 0, -1);
	}
	if (key_num == DOWN_KEY)
	{
		printf("do");
		ft_map_swap(data, 1, 0);
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
	mlx_hook((*data)->mlx_win, 2, 1L << 0, ft_remake_map, data);
	// mlx_hook((*data)->mlx_win, 17, 1L << 2, ft_close, data);
	mlx_loop((*data)->mlx);
}
