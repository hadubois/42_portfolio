/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:12:58 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/20 16:50:35 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**copy_map(t_map *map)
{
	char	**res;
	size_t	i;

	res = malloc(sizeof(char *) * (map->height + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		res[i] = ft_strdup(map->map[i]);
		if (!res[i])
		{
			i = 0;
			while (res[i])
			{
				free(res[i]);
				i++;
			}
			return (free(res), NULL);
		}
		++i;
	}
	res[i] = NULL;
	return (res);
}

void	explore(char **map, int x, int y)
{
	if (!map[y] || !map[y][x] || map[y][x] == '1')
		return ;
	if (map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	explore(map, x, y + 1);
	explore(map, x, y - 1);
	explore(map, x + 1, y);
	explore(map, x - 1, y);
}

int	is_possible(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
