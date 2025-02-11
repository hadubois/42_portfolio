/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:51:06 by hadubois          #+#    #+#             */
/*   Updated: 2024/12/03 16:00:42 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	i = -1;
	count = 0;
	while (s[++i])
		count += ft_putchar(s[i]);
	return (count);
}

int	ft_putnbr(int n)
{
	long	ln;
	char	x;
	int		count;

	count = 0;
	ln = n;
	if (ln < 0)
	{
		count += ft_putchar('-');
		ln *= -1;
	}
	if (ln > 9)
		count += ft_putnbr(ln / 10);
	x = ln % 10 + '0';
	count += ft_putchar(x);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long	ln;
	char	x;
	int		count;

	ln = n;
	count = 0;
	if (ln < 0)
		ln *= -1;
	if (ln > 9)
		count += ft_putnbr_unsigned(ln / 10);
	x = ln % 10 + '0';
	count += ft_putchar(x);
	return (count);
}

int	ft_putnbr_hex(unsigned long n, int up_base)
{
	unsigned long	ln;
	int				count;
	char			*base;

	ln = n;
	count = 0;
	base = "0123456789abcdef";
	if (up_base)
		base = "0123456789ABCDEF";
	if (ln >= 16)
		count += ft_putnbr_hex(ln / 16, up_base);
	count += ft_putchar(base[ln % 16]);
	return (count);
}
