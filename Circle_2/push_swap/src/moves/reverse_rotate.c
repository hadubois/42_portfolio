/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:30:47 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/07 11:41:27 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	reverse_rotate(char stack, t_list **list)
{
	if (!(*list))
		return ;
	(*list) = (*list)->prev;
	if (stack == 'a')
		ft_printf("rra\n");
	if (stack == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate('\0', a);
	reverse_rotate('\0', b);
	ft_printf("rrr\n");
}
