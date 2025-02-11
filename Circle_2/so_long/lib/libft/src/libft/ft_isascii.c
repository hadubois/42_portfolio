/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:00:22 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 12:14:19 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	x = 0;
	int	y = 256;
	int	z = 127;

	printf("ft_isascii(x) return: %d\n", ft_isascii(x));
	printf("   isascii(x) return: %d\n",    isascii(x));

	printf("ft_isascii(y) return: %d\n", ft_isascii(y));
	printf("   isascii(y) return: %d\n",    isascii(y));

	printf("ft_isascii(z) return: %d\n", ft_isascii(z));
	printf("   isascii(z) return: %d\n",    isascii(z));
	return (0);
}
*/
