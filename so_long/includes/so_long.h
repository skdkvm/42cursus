/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:44:24 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/15 18:21:53 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 128

# include "../libft/libft.h"
# include "/usr/local/include/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>


typedef struct s_texture
{
	int			width;
	int			height;
	void		*texture;
	char		*data;
}t_texture;

typedef struct s_info
{
	void			*mlx_ptr;
	void			*window_ptr;
	t_list			*map_ptr;
	unsigned int	player;
	unsigned int	collect;
	unsigned int	exit;
	unsigned int	player_pos[2];
	t_texture		*fl_texture;
	t_texture		*pl_texture;
	t_texture		*wa_texture;
	t_texture		*co_texture;
	t_texture		*ex_texture;
}t_info;

t_info	*ft_parsing(char *map);
void	free_info(t_info *info);
void	close_error(char *line, t_info *info);
int		get_next_line(int fd, char **line);
void	parse_map(t_info *info);
void	check_wall(t_info *info, char *str);
void	check_collect_exit(t_info *info, char *str, int line_index);
void	ft_display(t_info *info);
void	quit_game(t_info *info);
int		close_game(void *info);
void	load_textures(t_info *info);
void	free_texture(void *mlx_ptr, t_texture *texture);
void	display_map(t_info *info);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(char *s1, char *s2);
void	move_collect(t_info	*info);

#endif
