/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:56:27 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/08 16:19:34 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_is_set(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_start_n_stop(const char *s1, const char *set,
size_t *start, size_t *end)
{
	size_t	i;

	i = 0;
	while (ft_is_set(set, s1[i]))
	{
		*start = *start + 1;
		i++;
	}
	i = *end - 1;
	while (ft_is_set(set, s1[i]))
	{
		*end = *end - 1;
		i--;
	}
	if (*end < *start)
	{
		*start = 0;
		*end = 0;
	}
}

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_str;

	if (s1 && !set)
		return (strdup(s1));
	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = strlen(s1);
	ft_start_n_stop(s1, set, &start, &end);
	new_str = malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i + start < end)
	{
		new_str[i] = s1[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
