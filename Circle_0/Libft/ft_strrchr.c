/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:21:32 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/21 11:25:04 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*index;

	i = ft_strlen(s);
	index = (char *)s;
	while (i)
	{
		if ((unsigned char)c == s[i])
			return (index + i);
		i--;
	}
	if ((unsigned char)c == s[i])
		return (index + i);
	return (NULL);
}

/*
int	main(void)
{
	char	s1[] = "just one thing make me forgive : red red wine";
	char	s2[] = "just one thing make me forgive : red red wine";
	char 	c1 = 'd';
	char 	c2 = 'd';

	printf("ft_strrchr() return: %s \n", ft_strrchr(s1, c1));
	printf("   strrchr() return: %s \n",    strrchr(s2, c2));
	return (0);
}
*/
