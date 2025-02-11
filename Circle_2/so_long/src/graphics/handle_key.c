/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:40:20 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/28 16:00:57 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	exit_game(t_params *params)
{
	cleanup(params);
	exit(ft_printf("EXIT_GAME\n(with mouse)\n"));
	return (1);
}

void	print_moves(t_params *params, int state)
{
	if (state == 0)
		ft_printf("You made [%d] ", params->moves++ + 1);
	else
		ft_printf("\nThe WINNER is...\n...you!\nWith [%d] ",
			params->moves++ + 1);
	if (params->moves > 1)
		ft_printf("moves.\n");
	else
		ft_printf("move.\n");
	if (state != 0)
	{
		ft_printf("====================CREDITS====================\n");
		ft_printf("\nGraphisme                              UwU :)\n\n");
		ft_printf("===============================================\n");
	}
}

void	move_player(t_params *params, int new_x, int new_y)
{
	if (params->map->map[new_y][new_x] == '1')
		return ;
	if (params->map->map[new_y][new_x] == 'C')
	{
		params->map->c--;
		params->map->map[new_y][new_x] = '0';
	}
	if (params->map->exit_x == new_x && params->map->exit_y == new_y
		&& params->map->c == 0)
	{
		print_moves(params, 1);
		cleanup(params);
		exit(1);
	}
	params->map->map[params->map->player_y][params->map->player_x] = '0';
	params->map->player_x = new_x;
	params->map->player_y = new_y;
	params->map->map[new_y][new_x] = 'P';
	print_moves(params, 0);
	mlx_clear_window(params->mlx, params->win);
	draw_map(params, 0, 0);
}

int	handle_key(int keycode, t_params *params)
{
	if (keycode == 65307)
	{
		cleanup(params);
		exit(ft_printf("EXIT_GAME\n(with esc key)\n"));
	}
	if (keycode == 119)
		move_player(params, params->map->player_x, params->map->player_y - 1);
	if (keycode == 97)
		move_player(params, params->map->player_x - 1, params->map->player_y);
	if (keycode == 115)
		move_player(params, params->map->player_x, params->map->player_y + 1);
	if (keycode == 100)
		move_player(params, params->map->player_x + 1, params->map->player_y);
	return (1);
}
