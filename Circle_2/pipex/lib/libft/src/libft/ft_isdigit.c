/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:46:36 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 12:00:00 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_isdigit() return: %d\n", ft_isdigit(av[1][0]));
		printf("   isdigit() return: %d\n",    isdigit(av[1][0]));
	}
	return (0);
}
*/
