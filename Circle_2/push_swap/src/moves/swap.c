/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:15:16 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/07 11:42:13 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	swap(char stack, t_list **list)
{
	int	temp;

	if (!(*list))
		return ;
	temp = (*list)->value;
	(*list)->value = (*list)->next->value;
	(*list)->next->value = temp;
	if (stack == 'a')
		ft_printf("sa\n");
	if (stack == 'b')
		ft_printf("sb");
}

void	ss(t_list **a, t_list **b)
{
	swap('\0', a);
	swap('\0', b);
	ft_printf("ss\n");
}
