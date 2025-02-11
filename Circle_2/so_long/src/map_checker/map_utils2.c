/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:09:51 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 18:43:52 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	open_file(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	map->fd = fd;
	return (1);
}

int	is_valable(int c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

int	is_ber_file(char *s)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t')
		len--;
	if (len > 1 && s[len] == 'r')
	{
		len--;
		if (len > 1 && s[len] == 'e')
		{
			len--;
			if (len > 1 && s[len] == 'b')
			{
				len--;
				if (len > 1 && s[len] == '.')
				{
					len--;
					if (len > 1 && is_valable(s[len]))
						return (1);
				}
			}
		}
	}
	return (0);
}

void	set_player_pos(t_map *map, int x, int y)
{
	map->player_x = x;
	map->player_y = y;
}

void	set_nb_lines(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
		i++;
	map->height = i;
}
