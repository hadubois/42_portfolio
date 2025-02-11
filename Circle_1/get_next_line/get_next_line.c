/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:43:09 by hadubois          #+#    #+#             */
/*   Updated: 2024/12/14 17:35:09 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stach)
{
	char	*temp;
	char	*buf;
	ssize_t	b_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && !ft_strchr(stach, '\n'))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read < 0)
			return (free(buf), free(stach), NULL);
		if (b_read == 0)
			break ;
		buf[b_read] = '\0';
		temp = stach;
		stach = ft_strjoin(temp, buf);
		if (!stach)
			return (free(temp), free(buf), NULL);
		free(temp);
	}
	free(buf);
	return (stach);
}

size_t	ft_search_n(char *str)
{
	size_t	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] != '\n')
		return (0);
	else if (str[i] == '\n')
		++i;
	return (i);
}

char	*ft_extract(char *stach)
{
	char	*res;
	size_t	n;
	size_t	i;

	if (!stach || stach[0] == '\0')
		return (NULL);
	n = ft_search_n(stach);
	if (!n)
		return (ft_strdup(stach));
	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = stach[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_remaining(char *stach)
{
	char	*res;
	size_t	n;
	size_t	i;

	if (!stach)
		return (NULL);
	n = ft_search_n(stach);
	if (!n)
		return (free(stach), NULL);
	if (ft_strlen(stach) == n)
		return (free(stach), NULL);
	res = malloc(sizeof(char) * (ft_strlen(stach) - n + 1));
	if (!res)
		return (free(stach), NULL);
	i = 0;
	while (stach[n])
	{
		res[i] = stach[n];
		++i;
		++n;
	}
	res[i] = '\0';
	free(stach);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stach;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stach), NULL);
	stach = ft_read(fd, stach);
	if (!stach)
		return (NULL);
	line = ft_extract(stach);
	stach = ft_remaining(stach);
	return (line);
}

/*
# include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("file.txt", O_RDONLY);
	i = 0;

	//premier appel gnl
	line = get_next_line(fd);
	++i;
	printf("[%d] {%s}\n", i, line);
	free(line);
	//premier appel gnl
	line = get_next_line(fd);
	++i;
	printf("[%d] {%s}\n", i, line);
	free(line);
	//premier appel gnl
	line = get_next_line(fd);
	++i;
	printf("[%d] {%s}\n", i, line);
	free(line);
	//premier appel gnl
	line = get_next_line(fd);
	++i;
	printf("[%d] {%s}\n", i, line);
	free(line);

	return (EXIT_SUCCESS);
}
*/
