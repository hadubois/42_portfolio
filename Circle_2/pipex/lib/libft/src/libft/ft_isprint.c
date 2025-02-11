/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:17:05 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 12:18:27 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	x = 0;
	int	y = 32;
	int	z = 126;

	printf("ft_isprint(x) return: %d\n", ft_isprint(x));
	printf("   isprint(x) return: %d\n",    isprint(x));

	printf("ft_isprint(y) return: %d\n", ft_isprint(y));
	printf("   isprint(y) return: %d\n",    isprint(y));

	printf("ft_isprint(z) return: %d\n", ft_isprint(z));
	printf("   isprint(z) return: %d\n",    isprint(z));
	return (0);
}
*/
