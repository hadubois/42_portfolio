/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:51:51 by hadubois          #+#    #+#             */
/*   Updated: 2024/12/03 16:24:06 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	pn;

	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	pn = (unsigned long)ptr;
	count = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_putnbr_hex(pn, 0);
	return (count);
}

static int	ft_delestage(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (format[1] == '%')
		count += ft_putchar('%');
	else if (format[1] == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format[1] == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format[1] == 'd' || format[1] == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format[1] == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (format[1] == 'x')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), 0);
	else if (format[1] == 'X')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), 1);
	else if (format[1] == 'p')
		count += ft_putptr(va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	count;

	va_start(ap, format);
	i = 0;
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (format[0] == '%' && format[1] != '\0')
		{
			count += ft_delestage(format, ap);
			format++;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		format++;
	}
	va_end(ap);
	return (count);
}

/*
#include <stdio.h>
int main(void)
{
	int	count1;
	int	count2;

	count1 = ft_printf("%% <> %c <> %d\n", 'H', -42);
	count2 =    printf("%% <> %c <> %d\n", 'H', -42);
	printf("%d\n", count1);
	printf("%d\n", count2);
	return (0);
}
*/
