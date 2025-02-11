/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:37:08 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 11:42:32 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	if (n == 0 || src == dest)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}

/*
int	main(void)
{
// str
	char	str1[] = "salut     brown";
	char	str2[] = "salut     brown";
	size_t	n = 5;
	char *res1 = (char *)ft_memmove(str1, str1 + 10, n * sizeof(char));
	char *res2 = (char *)   memmove(str2, str2 + 10, n * sizeof(char)); 

	printf("ft_memmove() return: %s\n", res1);
	printf("   memmove() return: %s\n", res2); 

// array 
	int	src3[4] = {1, 2, 3, 4};
	int	src4[4] = {1, 2, 3, 4};
	size_t	n1 = 0;
	int	*tableau1= (int *)ft_memmove(src3, src3, n1 * sizeof(int));
	int	*tableau2= (int *)   memmove(src4, src4, n1 * sizeof(int));

	for (int i = 0; i < 4 ; i++)
	{
		printf("%d ", tableau1[i]); 
	}
	printf("\n"); 
	for (int i = 0; i < 4 ; i++)
	{
		printf("%d ", tableau2[i]);
	}
	return (0);
}
*/
