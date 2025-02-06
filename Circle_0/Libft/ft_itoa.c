/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:52:21 by hadubois          #+#    #+#             */
/*   Updated: 2024/11/25 11:07:15 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_neg(int ln);
static int	ft_len_int(long ln);
static char	*ft_fill_str(char *str, long ln, int len_n);

static int	ft_is_neg(int ln)
{
	if (ln < 0)
		return (1);
	return (0);
}

static int	ft_len_int(long ln)
{
	size_t	len;

	len = 0;
	while (ln > 9)
	{
		len++;
		ln /= 10;
	}
	return (len + 1);
}

static char	*ft_fill_str(char *str, long ln, int len_n)
{
	len_n--;
	while (len_n >= 0)
	{
		str[len_n] = ln % 10 + 48;
		ln /= 10;
		len_n--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len_n;
	long	ln;

	len_n = 0;
	ln = n;
	if (ft_is_neg(n))
	{
		len_n++;
		ln *= -1;
	}
	len_n += ft_len_int(ln);
	str = malloc(sizeof(char) * (len_n + 1));
	if (!str)
		return (NULL);
	str[len_n] = '\0';
	str = ft_fill_str(str, ln, len_n);
	if (ft_is_neg(n))
		str[0] = '-';
	return (str);
}

/*
int	main(void)
{
	int		n = -2147483648;
	char	*str;

	str = ft_itoa(n);
	printf("ft_itoa() return: %s", str);
	return (0);
}
*/
