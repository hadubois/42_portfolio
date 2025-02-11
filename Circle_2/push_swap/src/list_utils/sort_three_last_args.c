/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_last_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:53 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/04 11:55:53 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three_args_in_a(t_list **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->prev->value)
		rotate('a', a);
	else if ((*a)->next->value > (*a)->prev->value)
		reverse_rotate('a', a);
	if ((*a)->value > (*a)->next->value)
		swap('a', a);
}
