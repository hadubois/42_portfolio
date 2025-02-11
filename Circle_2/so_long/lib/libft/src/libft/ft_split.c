/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:48:59 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 11:05:08 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	ft_count_words(const char *s, char c);
static size_t	ft_count_chars(const char *index, const char c);
static char		*ft_fill_lines(const char *s, char c);
static int		ft_free_memory(char **tab, size_t i);

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s || *s == '\0')
		return (0);
	i = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static size_t	ft_count_chars(const char *index, const char c)
{
	size_t	count;

	count = 0;
	while (index[count] && index[count] != c)
		count++;
	return (count);
}

static char	*ft_fill_lines(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = ft_count_chars(s, c);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	j = 0;
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	return (line);
}

static int	ft_free_memory(char **tab, size_t i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**final_tab;

	if (!s)
		return (NULL);
	final_tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!final_tab)
		return (NULL);
	final_tab[ft_count_words(s, c)] = NULL;
	i = 0;
	while (*s)
	{
		if (s[0] == c)
		{
			s++;
			continue ;
		}
		final_tab[i] = ft_fill_lines(s, c);
		if (!final_tab[i] && ft_free_memory(final_tab, i))
			return (NULL);
		s += ft_count_chars(s, c);
		i++;
	}
	return (final_tab);
}

/*
int	main(void)
{
	char	*s = "salut,les,rangers";
	char	c = ',';
	char	**final_tab = ft_split(s, c);

	printf(">%ld<\n", ft_count_words(s, c));
	for (size_t i = 0; i < ft_count_words(s, c); i++)
		printf("tab[%ld]: >%s<\n", i, final_tab[i]);
	return (0);
}
*/
