/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:58:09 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 11:58:18 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_isalnum() return: %d\n", ft_isalnum(av[1][0]));
		printf("   isalnum() return: %d\n",    isalnum(av[1][0]));
	}
	return (0);
}
*/
