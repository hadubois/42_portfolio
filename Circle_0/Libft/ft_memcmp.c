/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:07 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 16:42:38 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char *s1 = "j'ai des petis problemes dans ma plantation";
	char *s2 = "j'ai des petis probpourquoi ca pousse pas";
	size_t	n = 9;

	printf("ft_memcmp() return: %d \n",
			(unsigned char)ft_memcmp(s1, s2, n * sizeof(char)));
	printf("   memcmp() return: %d \n",
			(unsigned char)   memcmp(s1, s2, n * sizeof(char)));

	int	tab0[4] = {1, 2, 3, 4};
	int	tab1[4] = {1, 2, 3, 1};
	size_t	x = 3;

	printf("ft_memcmp() return: %d \n",
			(unsigned char)ft_memcmp(tab0, tab1, x * sizeof(int)));
	printf("   memcmp() return: %d \n",
			(unsigned char)   memcmp(tab0, tab1, x * sizeof(int)));
	return (0);
}
*/
