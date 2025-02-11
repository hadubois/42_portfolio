/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:43:02 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/14 13:52:10 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*index;

	i = 0;
	index = (char *)big;
	if (*little == '\0')
		return (index);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little [j] && i + j < len)
			j++;
		if (j == ft_strlen(little))
			return (index + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char *big = "";
	char *little = "";
	size_t	n = 7;
	printf("ft_strnstr() return: %s \n", ft_strnstr(big, little, n));
//	printf("   strnstr() return: %s \n",    strnstr(s1, s2, n));
	return (0);
}
*/
