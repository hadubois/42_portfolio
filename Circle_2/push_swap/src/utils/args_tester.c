/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:01:42 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 14:37:28 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_int(char *str)
{
	int		i;

	if (str[0] == 0)
		return (0);
	i = 0;
	str = ft_strtrim(str, " ");
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (str[i] == 0)
		return (free(str), 0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (free(str), 0);
		++i;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (free(str), 0);
	if ((str[0] == '+' || str[0] == '-') && str[1] == 0)
		return (free(str), 0);
	return (free(str), 1);
}

int	ft_locate_nb(char **big, size_t pos_little)
{
	size_t	i;
	char	*little;

	i = pos_little;
	little = big[i];
	while (big[++i])
	{
		if (ft_atol(big[i]) == ft_atol(little))
			return (1);
	}
	return (0);
}

int	test_args(char **av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!is_int(av[i]))
			return (0);
		++i;
	}
	return (1);
}
