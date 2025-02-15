/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:25:44 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/10 16:03:38 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		++i;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;
	int	base;

	i = 0;
	s = 1;
	res = 0;
	base = 10;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * base + (nptr[i] - '0');
		i++;
	}
	return (res * s);
}
