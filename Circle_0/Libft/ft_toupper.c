/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:29 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 10:40:02 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
int	main(void)
{
	int	c1 = 'z';
	int	c2 = 'z';

	printf("ft_toupper() return: %d\n", ft_toupper(c1));
	printf("   toupper() return: %d\n",    toupper(c2));
	return (0);
}
*/
