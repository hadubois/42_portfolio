/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:16:24 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/14 14:55:49 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	x;

	if (fd < 0)
		return ;
	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	if (ln > 9)
		ft_putnbr_fd(ln / 10, fd);
	x = ln % 10 + '0';
	write(fd, &x, 1);
}

/*
int	main(void)
{
	int	nbr = -2147483648;
	int	fd = 1;
	ft_putnbr_fd(nbr, fd);
	return (0);
}
*/
