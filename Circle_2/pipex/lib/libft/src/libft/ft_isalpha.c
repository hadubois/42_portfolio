/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:30:13 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 10:55:06 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isalpha(int c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
		return (1);
	return (0);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_isalpha() return: %d\n", ft_isalpha(av[1][0]));
		printf("   isalpha() return: %d\n",    isalpha(av[1][0]));
	}
	return (0);
}
*/
