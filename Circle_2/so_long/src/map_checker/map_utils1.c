/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:03:09 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/28 15:34:15 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_valid_item(char item, t_map *map)
{
	if (item == 'C')
	{
		map->c++;
		return (1);
	}
	else if (item == 'E')
	{
		map->e++;
		return (1);
	}
	else if (item == 'P')
	{
		map->p++;
		return (1);
	}
	else if (item == '0' || item == '1')
		return (1);
	return (0);
}

int	handle_items_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n')
		{
			if (!is_valid_item(map->map[i][j], map))
				return (0);
			if (map->map[i][j] == 'E')
			{
				map->exit_x = j;
				map->exit_y = i;
			}
			if (map->map[i][j] == 'P')
				set_player_pos(map, j, i);
			j++;
		}
		++i;
	}
	if (map->c < 1 || map->p != 1 || map->e != 1)
		return (0);
	return (1);
}

int	is_horizontal_wall(char *s)
{
	size_t	i;
	size_t	len;

	len = lenwinoeof(s);
	i = 0;
	while (s[i] && i < len)
	{
		if (s[i] != '1')
			return (0);
		++i;
	}
	return (1);
}

int	is_outline(t_map *map)
{
	size_t	i;
	size_t	nb_lines;

	nb_lines = map->height;
	i = 0;
	while (i < nb_lines)
	{
		if ((i == 0 || i == nb_lines - 1) && !is_horizontal_wall(map->map[i]))
			return (0);
		else
		{
			if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
				return (0);
		}
		++i;
	}
	return (1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		++i;
	}
	ft_printf("\n");
}
