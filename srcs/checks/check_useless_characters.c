/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_useless_characters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:34:42 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 19:34:45 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_check_useless(char c)
{
	return ((c == '1') || (c == '0' || c == 'P' || c == 'E' || c == 'C'
			|| c == '\n'));
}

void	ft_useless_characters(t_maps **maps)
{
	int		i;
	int		k;
	bool	flag;

	i = 0;
	while ((*maps)->map[i])
	{
		k = 0;
		while ((*maps)->map[i][k])
		{
			flag = ft_check_useless((*maps)->map[i][k]);
			if (flag == false)
			{
				printf("useless characters\n");
				ft_free_maps(maps, 1);
			}
			k++;
		}
		i++;
	}
}
