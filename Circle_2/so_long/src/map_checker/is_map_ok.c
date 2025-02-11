/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:36:55 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 18:49:08 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	fill_map(t_map *map)
{
	char	*line;
	char	*temp;
	char	*bigline;

	bigline = NULL;
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		temp = bigline;
		bigline = ft_strjoin(temp, line);
		free(temp);
		free(line);
		temp = bigline;
		bigline = ft_strjoin(bigline, "^");
		free(temp);
		line = get_next_line(map->fd);
	}
	if (bigline)
	{
		map->map = ft_split(bigline, '^');
		if (!map->map)
			return (0);
		free(bigline);
	}
	return (1);
}

size_t	lenwinoeof(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

int	is_rectangle(t_map *map)
{
	int	i;

	i = 0;
	map->width = lenwinoeof(map->map[i]);
	while (map->map[i])
	{
		if (lenwinoeof(map->map[i]) != map->width)
			return (0);
		++i;
	}
	return (1);
}

int	is_map_ok(t_map *map)
{
	char	**map_cpy;

	if (!fill_map(map))
		return (close(map->fd), 0);
	close (map->fd);
	if (!map->map)
		return (0);
	if (!is_rectangle(map))
		return (0);
	if (!handle_items_pos(map))
		return (0);
	set_nb_lines(map);
	if (!is_outline(map))
		return (0);
	map_cpy = copy_map(map);
	if (!map_cpy)
		return (0);
	explore(map_cpy, map->player_x, map->player_y);
	if (!is_possible(map_cpy))
		return (free_split_elt(map_cpy), 0);
	free_split_elt(map_cpy);
	return (1);
}
