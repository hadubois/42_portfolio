/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:53:53 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:29 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*
int	main(void)
{
//	STR VERSION	//
	char	s1[] = "xx la tete a toto";
	char	s2[] = "xx la tete a toto";
	size_t	n = 2;
	ft_bzero(s1, n * sizeof(char));
	   bzero(s2, n * sizeof(char));
	printf("ft_bzero() return: %s\n", s1);
	printf("   bzero() return: %s\n", s2);

//	ARRAY VERSION	//
	int	tab1[4] = {1, 2, 3, 4};
	int	tab2[4] = {1, 2, 3, 4};
	size_t n1 = 2;
	ft_bzero(tab1, n1 * (sizeof(int)));
	   bzero(tab2, n1 * (sizeof(int)));
	for (int i = 0; i < 4; i++)
			printf("%d ", tab1[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
			printf("%d ", tab2[i]);
	return (0);
}
*/
