/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:45:06 by hadubois          #+#    #+#             */
/*   Updated: 2024/12/14 17:04:48 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*index;

	if (!s)
		return (NULL);
	i = 0;
	index = (char *)s;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			return (index);
		i++;
		index++;
	}
	if ((unsigned char)c == '\0')
		return (index);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	ssize_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		++i;
		++j;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s1;

	if (!s)
		return (NULL);
	i = 0;
	s1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s1 == NULL)
		return (0);
	s1[ft_strlen(s)] = '\0';
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	return (s1);
}
