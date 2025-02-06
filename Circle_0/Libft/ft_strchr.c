/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:08:55 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/21 11:13:40 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*index;

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

/*
int	main(void)
{
	char	s1[] = "ainz Ooal gown ";
	char	s2[] = "ainz Ooal gown ";
	char 	c1 = '\200';
	char 	c2 = '\200';

	printf("ft_strchr() return: %s \n", ft_strchr(s1, c1));
	printf("   strchr() return: %s \n",    strchr(s2, c2));
	return (0);
}
*/
