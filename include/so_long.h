/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/12/08 20:28:41 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
// # include <minilibx-linux/mlx.h>
# include <sys/stat.h>
# include <sys/types.h>

# define PIXEL_HIGTH 1980
# define PIXEL_WIDTH 1080
# define WINDOWSIZE 50
//shift
#define ESC_KEY 65307
#define UP_KEY 119
#define DOWN_KEY 115
#define LEFT_KEY 97
#define RIGHT_KEY 100

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

typedef struct s_data
{
	t_maps	*maps;
	void	*mlx;
	void	*mlx_win;
	void	*wall_image;
	void	*space_image;
	void	*player_image;
	void	*collection_image;
	void	*exit_image;

}			t_data;

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
void		ft_new_data(t_data **data, t_maps **maps);
void		ft_free_data(t_data **data, int flag);
void		ft_mlx_make(t_data **data);

#endif
