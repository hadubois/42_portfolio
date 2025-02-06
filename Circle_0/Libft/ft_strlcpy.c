/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:46 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/13 22:15:13 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	dest1[30] = "\0\0\0\0\0\0\0\0\0";
	char	dest2[30] = "\0\0\0\0\0\0\0\0\0";
	char	*src1 = "salut a toi jeune entrepreneur!";
	char	*src2 = "salut a toi jeune entrepreneur!";
	int		n = 0;

	printf("ft_strlcpy() return: %ld\n", ft_strlcpy(dest1, src1, n));
	printf("   strlcpy() return: %ld\n", ft_strlcpy(dest2, src2, n));
	printf("dest1 : %s\n", dest1);
	printf("dest2 : %s\n", dest2);
	return(0);
}
*/
