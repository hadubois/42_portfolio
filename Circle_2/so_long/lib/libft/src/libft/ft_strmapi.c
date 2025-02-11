/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:00:52 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 10:56:32 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	new_str[ft_strlen(s)] = '\0';
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}

/*
char	ft_test(unsigned int i, char c)
{
	(void)i;
	if (ft_islower(c))
		c -= 32;
	return (c);
}

int	main(void)
{
//	char	*s = "";
	printf("ft_strmapi() return: >%s<\n", ft_strmapi(NULL, ft_test));
	return(0);
}
*/
