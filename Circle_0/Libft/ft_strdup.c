/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:06:13 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/12 19:06:15 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s1 == NULL)
		return (0);
	s1[ft_strlen(s)] = '\0';
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	return (s1);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_strdup() return: %s\n", ft_strdup(av[1]));
		printf("   strdup() return: %s\n",    strdup(av[1]));
	}
	return (0);
}
*/
