/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:07:51 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/17 21:07:58 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			++i;
		}
		free(map->map);
	}
	if (map)
		free(map);
}

void	free_split_elt(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		++i;
	}
	free(a);
}

void	cleanup(t_params *params)
{
	free_map(params->map);
	if (params->bg)
		mlx_destroy_image(params->mlx, params->bg);
	if (params->player_img)
		mlx_destroy_image(params->mlx, params->player_img);
	if (params->floor_img)
		mlx_destroy_image(params->mlx, params->floor_img);
	if (params->collectible_img)
		mlx_destroy_image(params->mlx, params->collectible_img);
	if (params->exit_img)
		mlx_destroy_image(params->mlx, params->exit_img);
	if (params->wall_img)
		mlx_destroy_image(params->mlx, params->wall_img);
	if (params->win)
		mlx_destroy_window(params->mlx, params->win);
	if (params->mlx)
	{
		mlx_destroy_display(params->mlx);
		free(params->mlx);
	}
	free(params);
}
