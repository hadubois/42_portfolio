/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:03:53 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/09 13:21:14 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	find_cost(int value, int cible, t_list *dest, t_list *src)
{
	int		cost;
	size_t	value_i;
	size_t	cible_i;

	value_i = find_index_of(value, src);
	cible_i = find_index_of(cible, dest);
	if (cible_i > middle(dest) && cible_i == size_of(dest))
		cible_i = 1;
	else if (cible_i > middle(dest))
		cible_i = size_of(dest) - cible_i;
	if (value_i > middle(src) && value_i == size_of(src))
		value_i = 1;
	else if (value_i > middle(src))
		value_i = size_of(src) - value_i;
	cost = value_i + cible_i;
	return (cost);
}

int	lowest_cost(t_list *dest, t_list *src)
{
	t_list	*first;
	int		current_cost;
	int		value;

	if (!dest)
		return (src->value);
	first = src;
	current_cost = find_cost(src->value, find_cible_in(dest, src->value),
			dest, first);
	value = src->value;
	while (src)
	{
		if (current_cost > find_cost(src->value, find_cible_in(dest,
					src->value), dest, first))
		{
			current_cost = find_cost(src->value, find_cible_in(dest,
						src->value), dest, first);
			value = src->value;
		}
		src = src -> next;
		if (src == first)
			break ;
	}
	return (value);
}

void	do_best_move(int value, t_list **dest, t_list **src)
{
	int		cible;
	size_t	v_i;
	size_t	c_i;

	cible = find_cible_in(*dest, value);
	v_i = find_index_of(value, *src);
	c_i = find_index_of(cible, *dest);
	if (v_i > middle(*src) && c_i > middle(*src))
	{
		while (find_index_of(value, *src) != 0
			&& find_index_of(cible, *dest) != 0)
			rrr(dest, src);
	}
	else if (v_i < middle(*src) && c_i < middle(*src))
	{
		while (find_index_of(value, *src) != 0
			&& find_index_of(cible, *dest) != 0)
			rr(dest, src);
	}
	if (find_index_of(value, *src) != 0)
		put_on_top_of('b', src, value);
	if (find_index_of(cible, *dest) != 0)
		put_on_top_of('a', dest, cible);
	push_in('a', dest, src);
}
