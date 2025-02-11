/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:37:31 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/07 11:41:30 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

static void	push(t_list **dest, t_list **src)
{
	t_list	*temp;

	temp = (*src);
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	(*src) = (*src)->next;
	if (temp == temp->next)
		(*src) = NULL;
	if (!(*dest))
	{
		(*dest) = temp;
		(*dest)->next = (*dest);
		(*dest)->prev = (*dest);
	}
	else
	{
		temp->next = (*dest);
		temp->prev = (*dest)->prev;
		(*dest)->prev->next = temp;
		(*dest)->prev = temp;
		(*dest) = (*dest)->prev;
	}
}

void	push_in(char stack, t_list **dest, t_list **src)
{
	push(dest, src);
	if (stack == 'a')
		ft_printf("pa\n");
	if (stack == 'b')
		ft_printf("pb\n");
}
