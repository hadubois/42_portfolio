/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:00:52 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/14 10:20:55 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (n == 0 || dest == src)
		return (dest);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char dest1[] = "contrebande";
	char dest2[] = "contrebande";
	char src1[] = "rip\0st\0op";
	char src2[] = "rip\0st\0op";
	int	n = 10;
    printf("ft_memcpy() return: %s\n",
			(char *)ft_memcpy(dest1, src1, n * sizeof(char)));
    printf("memcpy() return: %s\n",
			(char *)memcpy(dest2, src2, n * sizeof(char)));

//	ARRAY VERSION	//
	int	tab1[4] = {1, 2, 3, 4};
	int	tab2[4] = {0, 0, 0, 0};
	size_t n1 = 4;
	(int *)ft_memcpy(tab1, tab2, n1 * sizeof(int));
	(int *)   memcpy(tab1, tab2, n1 * sizeof(int));
	for (int i = 0; i < 4; i++)
			printf("%d ", tab1[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
			printf("%d ", tab2[i]);
	return (0);
}
*/
