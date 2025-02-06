/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:31:39 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/14 12:43:31 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;
	size_t	lsrc;

	i = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if (ldest >= size)
		return (size + lsrc);
	while (src[i] && i + ldest < size - 1)
	{
		dest[ldest + i] = src[i];
		i++;
	}
	dest[ldest + i] = '\0';
	return (ldest + lsrc);
}

/*
int	main(void)
{
	char	dest1[50] = "sal";
	char	dest2[50] = "sal";
	char	src1[] = "sations";
	char	src2[] = "sations";
	int		size = 0;

	printf("ft_strlcat() return :%ld\n", ft_strlcat(dest1, src1, size));
	printf("   strlcat() return :%ld\n",    strlcat(dest2, src2, size));
	printf("dest1 :%s\n", dest1);
	printf("dest2 :%s\n", dest2);
	return(0);
}
*/
