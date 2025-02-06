/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:56:08 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 18:58:58 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}

/*
int	main(void)
{
	int	*tab1;
	int	*tab2;
	size_t	n = 4;

	tab1 = ft_calloc(0, sizeof(int));
	tab2 =    calloc(0, sizeof(int));
	for (size_t i = 0; i < n; i++)
		printf("tab1[%ld]: %d ||tab2[%ld]: %d\n", i, tab1[i], i, tab2[i]);
       return (0);
}
*/
