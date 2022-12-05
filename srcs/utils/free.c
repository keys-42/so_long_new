/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:45:09 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 04:09:32 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(char **dst)
{
	int	i;

	i = 0;
	if (dst)
	{
		while (dst[i])
		{
			free(dst[i]);
			i++;
		}
		free(dst);
	}
}

void	ft_free_maps(t_maps **maps, int flag)
{
	if (*maps)
	{
		if ((*maps)->map)
			ft_free_map((*maps)->map);
		if ((*maps)->dfs_flag)
			ft_free_map((*maps)->dfs_flag);
		if ((*maps)->fd)
			close((*maps)->fd);
		free(*maps);
	}
	if (flag == 1)
	{
		exit(EXIT_FAILURE);
	}
}
