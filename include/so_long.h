/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/12/06 04:16:25 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_maps
{
	char	**map;
	char	**dfs_flag;
	int		fd;
	int		hight;
	int		width;
	int		wall_head;
	int		wall_tail;
	int		player_i;
	int		player_j;
	int		exit_i;
	int		exit_j;
	int		collection_num;
	int		flag;
}			t_maps;

void		ft_check(int argc, char **argv, t_maps **maps);
void		ft_new_maps(t_maps **maps);
void		ft_make_map(char *txt, t_maps **maps);
void		ft_free_maps(t_maps **maps, int flag);
void		ft_check_player(t_maps **maps);
void		ft_check_wall(t_maps **maps);
int			ft_isspace(int c);
void		ft_check_square(t_maps **maps);
void		ft_check_exit(t_maps **maps);
void		ft_check_collectible(t_maps **maps);
void		ft_useless_characters(t_maps **maps);
void		ft_check_can_goal(t_maps **maps);

#endif
