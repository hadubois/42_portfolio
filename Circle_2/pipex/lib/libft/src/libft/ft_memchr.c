/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:12 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/14 14:48:44 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == str[i])
			return (str + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
//str
	char	s1[] = "salut";
	char	s2[] = "salut";
	char 	c1 = '\200';
	char 	c2 = '\200';
	size_t	n = 6;

	printf("ft_memchr() return: %s \n",
			(char *)ft_memchr(s1, c1, n * sizeof(char)));
	printf("   memchr() return: %s \n",
			(char *)   memchr(s2, c2, n * sizeof(char)));
// tableau
	int	tab1[5] = {0, 1, 2, 3};
	int	tab2[5] = {0, 1, 2, 3};
	int 	x1 = 6;
	int 	x2 = 6;
	size_t	n1 = 4;
	int	*tableau1 = (int *)ft_memchr(tab1, x1, n1 * sizeof(int));
	int	*tableau2 = (int *)   memchr(tab2, x2, n1 * sizeof(int));

	if (tableau1 != NULL)
	{
		for (int i = 0; i < 4 ; i++)
		{
			printf("%d ", tableau1[i]); 
		}
	}
	if (tableau2 != NULL)
	{
		printf("\n");
		for (int i = 0; i < 4 ; i++)
		{
			printf("%d ", tableau2[i]);
		}
	}
	return (0);
}
*/
