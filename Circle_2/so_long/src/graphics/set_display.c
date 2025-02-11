/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:12:27 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	fill_background(t_params *params, int width, int height, unsigned int color)
{
	char	*pixel;
	char	*addr;
	int		x;
	int		y;

	addr = params->addr;
	addr = mlx_get_data_addr(params->bg, &params->bits_per_pixel,
			&params->line_length, &params->endian);
	if (!addr)
		return (0);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel = addr + (y * params->line_length + x
					* (params->bits_per_pixel / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
	return (1);
}

int	load_textures(t_params *params)
{
	int	width;
	int	height;

	params->player_img = mlx_xpm_file_to_image(params->mlx,
			"./textures/player.xpm", &width, &height);
	if (!params->player_img)
		return (cleanup(params), 0);
	params->wall_img = mlx_xpm_file_to_image(params->mlx,
			"./textures/wall.xpm", &width, &height);
	if (!params->wall_img)
		return (cleanup(params), 0);
	params->collectible_img = mlx_xpm_file_to_image(params->mlx,
			"./textures/collectible.xpm", &width, &height);
	if (!params->collectible_img)
		return (cleanup(params), 0);
	params->exit_img = mlx_xpm_file_to_image(params->mlx,
			"./textures/exit.xpm", &width, &height);
	if (!params->exit_img)
		return (cleanup(params), 0);
	return (1);
}

void	draw_map(t_params *params, size_t y, size_t x)
{
	mlx_put_image_to_window(params->mlx, params->win, params->bg, 0, 0);
	y = 0;
	while (y < params->map->height)
	{
		x = 0;
		while (x < params->map->width)
		{
			if (params->map->map[y][x] == '1')
				mlx_put_image_to_window(params->mlx, params->win,
					params->wall_img, x * 80, y * 80);
			else if (params->map->map[y][x] == 'C')
				mlx_put_image_to_window(params->mlx, params->win,
					params->collectible_img, x * 80, y * 80);
			else if (params->map->exit_x == (int)x
				&& params->map->exit_y == (int)y && params->map->c == 0)
				mlx_put_image_to_window(params->mlx, params->win,
					params->exit_img, x * 80, y * 80);
			else if (params->map->map[y][x] == 'P')
				mlx_put_image_to_window(params->mlx, params->win,
					params->player_img, x * 80, y * 80);
			x++;
		}
		y++;
	}
}

int	init_window(t_params *params)
{
	params->mlx = mlx_init();
	if (!params->mlx)
		return (0);
	params->win = mlx_new_window(params->mlx, (params->map->width) * 80,
			params->map->height * 80, "./so_long");
	if (!params->win)
		return (0);
	params->bg = mlx_new_image(params->mlx, (params->map->width) * 80,
			params->map->height * 80);
	if (!params->bg)
		return (0);
	if (!fill_background(params, (params->map->width) * 80,
			params->map->height * 80, 0x5a4bdc))
		return (0);
	if (!load_textures(params))
		return (0);
	draw_map(params, 0, 0);
	mlx_hook(params->win, 2, 1L << 0, handle_key, params);
	mlx_hook(params->win, 17, 0, exit_game, params);
	mlx_loop(params->mlx);
	cleanup(params);
	return (1);
}
