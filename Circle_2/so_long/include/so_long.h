/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:28:34 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/28 15:20:13 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/include/libft.h"

typedef struct s_map
{
	int		fd;
	char	**map;
	size_t	width;
	size_t	height;
	int		c;
	int		e;
	int		p;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_params
{
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;
	void	*player_img;
	void	*collectible_img;
	void	*bg;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		moves;
}	t_params;

int		is_ber_file(char *s);
int		is_possible(char **map);
int		is_map_ok(t_map *map);
char	**copy_map(t_map *map);
void	free_map(t_map *map);
void	free_split_elt(char **a);
void	cleanup(t_params *params);
void	explore(char **map, int x, int y);
size_t	lenwinoeof(char *str);
//map_utils1.c
void	print_map(char **map);
int		fill_map(t_map *map);
int		open_file(char *file, t_map *map);
int		is_ber_file(char *s);
int		is_outline(t_map *map);
int		handle_items_pos(t_map *map);
//map_utils2.c
void	set_player_pos(t_map *map, int x, int y);
void	set_nb_lines(t_map *map);
//graphics
int		exit_game(t_params *params);
int		init_window(t_params *params);
int		load_textures(t_params *params);
int		handle_key(int keycode, t_params *params);
void	draw_map(t_params *params, size_t y, size_t x);
#endif
