/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:29:45 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/12 19:18:21 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_nb_of_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Error: ARGS: Please put the right numbers of args.\n", 2);
		return (0);
	}
	return (1);
}

int	are_nbr(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!is_nbr(av[i]))
		{
			ft_putstr_fd("Error: ARGS: Please put only numbers.\n", 2);
			return (0);
		}
	}
	return (1);
}

int	is_nbr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		++i;
	if (!str[i])
		return (1);
	return (0);
}

int	are_valid_nbr(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			ft_putstr_fd("Error: ARGS: Please put only values > 0.\n", 2);
			return (0);
		}
	}
	return (1);
}
