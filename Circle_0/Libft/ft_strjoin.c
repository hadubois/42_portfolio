/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:41:05 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 19:41:27 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;	

	s3 = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		s3[i] = s2[i - ft_strlen(s1)];
		i ++;
	}
	s3[i] = '\0';
	return (s3);
}

/*
int	main(void)
{
	char	*s1 = "comamchero";
	char	*s2 = " is a very nice song HETPQOHETCW[OCT +_)(*&^%$#ng yo! ";

	printf("ft_strjoin() return: %s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
