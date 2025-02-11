/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:11:45 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/09 13:34:23 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

int	find_cible_in(t_list *dest, int value)
{
	int		cible;
	t_list	*first;

	if (!dest)
		exit(write(2, "Error\n", 6));
	first = dest;
	cible = find_max_value_in(dest);
	if (value < find_min_value_in(dest) || value > find_max_value_in(dest))
		cible = find_min_value_in(dest);
	else
	{
		while (dest)
		{
			if (dest->value > value && dest->value < cible)
				cible = dest->value;
			dest = dest->next;
			if (dest == first)
				break ;
		}
	}
	return (cible);
}

size_t	middle(t_list *list)
{
	size_t	size;

	if (!list)
		return (0);
	size = size_of(list);
	return (size / 2);
}

void	put_on_top_of(char s, t_list **list, int value)
{
	size_t	v_index;

	v_index = find_index_of(value, *list);
	while (v_index != 0)
	{
		if (v_index > middle(*list))
		{
			if (s == 'a')
				reverse_rotate('a', list);
			if (s == 'b')
				reverse_rotate('b', list);
		}
		else
		{
			if (s == 'a')
				rotate('a', list);
			if (s == 'b')
				rotate('b', list);
		}
		v_index = find_index_of(value, *list);
	}
}

int	find_max_in_chunk(t_list *list, int chunk)
{
	int	min;
	int	count;

	count = 0;
	min = find_min_value_in(list);
	while (count < chunk)
	{
		min = find_cible_in(list, min);
		++count;
	}
	return (min);
}

int	is_sort(t_list *list)
{
	t_list	*first;

	first = list;
	if (list == list->next)
		return (1);
	while (list->next != first)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}
