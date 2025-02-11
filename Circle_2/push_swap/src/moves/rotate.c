/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:28:27 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/07 11:41:55 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

void	rotate(char stack, t_list **list)
{
	if (!(*list))
		return ;
	(*list) = (*list)->next;
	if (stack == 'a')
		ft_printf("ra\n");
	if (stack == 'b')
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rotate('\0', a);
	rotate('\0', b);
	ft_printf("rr\n");
}
