/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:27 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 10:39:06 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
int	main(void)
{
	int	c1 = 'Z';
	int	c2 = 'Z';

	printf("ft_tolower() return: %d\n", ft_tolower(c1));
	printf("   tolower() return: %d\n",    tolower(c2));
	return (0);
}
*/
