/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:39 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 12:50:10 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
//	STR VERSION	//
	char	s1[] = "xx la tete a toto";
	char	s2[] = "xx la tete a toto";
	char	c = '0';
	size_t	n = 2;
	ft_memset(s1, c, n * sizeof(char));
	   memset(s2, c, n * sizeof(char));
	printf("ft_memset() return: %s\n", s1);
	printf("   memset() return: %s\n", s2);

//	ARRAY VERSION	//
	int	tab1[4] = {1, 2, 3, 4};
	int	tab2[4] = {1, 2, 3, 4};
	int	c1 = 0;
	size_t n1 = 2;
	ft_memset(tab1, c1, n1 * (sizeof(int)));
	   memset(tab2, c1, n1 * (sizeof(int)));
	for (int i = 0; i < 4; i++)
			printf("%d ", tab1[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
			printf("%d ", tab2[i]);
	return (0);
}
*/
