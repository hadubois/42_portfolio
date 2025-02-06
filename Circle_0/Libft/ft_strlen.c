/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:47 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 12:22:30 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_strlen return: %ld\n", ft_strlen(av[1]));
		printf("   strlen return: %ld\n",    strlen(av[1]));
	}
	return (0);
}
*/
