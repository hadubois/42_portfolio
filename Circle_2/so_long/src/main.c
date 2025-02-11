/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:27:32 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 18:21:13 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_params(t_map *map, t_params *params)
{
	params->map = map;
	params->bg = NULL;
	params->mlx = NULL;
	params->win = NULL;
	params->player_img = NULL;
	params->collectible_img = NULL;
	params->exit_img = NULL;
	params->wall_img = NULL;
	params->floor_img = NULL;
	params->addr = NULL;
	params->moves = 0;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->p = 0;
	map->c = 0;
	map->e = 0;
}

int	main(int ac, char *av[])
{
	t_map		*map;
	t_params	*params;

	map = malloc(sizeof(t_map));
	if (!map)
		return (EXIT_FAILURE);
	init_map(map);
	if (ac != 2)
		return (free_map(map), ft_printf("Error\ninvalidArgs\n"), EXIT_FAILURE);
	if (!is_ber_file(av[1]))
		return (free_map(map), ft_printf("Error\ninvalidFile\n"), EXIT_FAILURE);
	if (!open_file(av[1], map))
		return (free_map(map), ft_printf("Error\ninvalidFile\n"), EXIT_FAILURE);
	if (!is_map_ok(map))
		return (free_map(map), ft_printf("Error\ninvalidMap\n"), EXIT_FAILURE);
	params = malloc(sizeof(t_params));
	if (!params)
		return (free_map(map), EXIT_FAILURE);
	init_params(map, params);
	if (!init_window(params))
		free_map(map);
	free(params);
	return (EXIT_SUCCESS);
}
