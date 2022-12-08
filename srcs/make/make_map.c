/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:42:25 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 14:39:16 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_get_new_line(char *line)
{
	size_t	len;
	char	*new_line;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		new_line = ft_substr(line, 0, len - 1);
	free(line);
	return (new_line);
}

static void	ft_get_map(t_maps **maps, int i)
{
	char	*line;

	line = get_next_line((*maps)->fd);
	if (!line)
	{
		(*maps)->map = (char **)malloc((sizeof(char *) * (i + 1)));
		if (!((*maps)->map))
			ft_free_maps(maps, 1);
		(*maps)->map[i] = NULL;
		return ;
	}
	else
	{
		ft_get_map(maps, i + 1);
		line = ft_get_new_line(line);
		(*maps)->map[i] = line;
		return ;
	}
}

void	ft_make_map(char *txt, t_maps **maps)
{
	(*maps)->fd = open(txt, O_RDONLY);
	if ((*maps)->fd < 0)
	{
		free(*maps);
		exit(EXIT_FAILURE);
	}
	ft_get_map(maps, 0);
}
