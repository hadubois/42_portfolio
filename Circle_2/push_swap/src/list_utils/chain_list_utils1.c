/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:21:36 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/09 13:37:07 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/ft_printf.h"

size_t	find_index_of(int value, t_list *list)
{
	size_t	index_value;
	t_list	*first;

	first = list;
	index_value = 0;
	while (list)
	{
		if (list->value == value)
			return (index_value);
		++index_value;
		list = list->next;
		if (list == first)
			break ;
	}
	exit(write(2, "Error\n", 6));
}

size_t	size_of(t_list *head)
{
	size_t	count;
	t_list	*first;

	count = 0;
	first = head;
	while (head)
	{
		count++;
		head = head->next;
		if (head == first)
			return (count);
	}
	return (count);
}

int	find_max_value_in(t_list *list)
{
	int		max_value;
	t_list	*first;

	if (!list)
		exit(write(2, "Error\n", 6));
	first = list;
	max_value = list->value;
	while (list)
	{
		if (list->value > max_value)
			max_value = list->value;
		list = list->next;
		if (list == first)
			break ;
	}
	return (max_value);
}

int	find_cible_of(int value, t_list *list)
{
	int		cible;
	t_list	*first;

	first = list;
	cible = find_max_value_in(list);
	while (list)
	{
		if (list->value > value && list->value < cible)
			cible = list->value;
		list = list->next;
		if (list == first)
			break ;
	}
	return (cible);
}

int	find_min_value_in(t_list *list)
{
	int		min_value;
	t_list	*first;

	if (!list)
		exit(write(2, "Error\n", 6));
	first = list;
	min_value = list->value;
	while (list)
	{
		if (list->value < min_value)
			min_value = list->value;
		list = list->next;
		if (list == first)
			break ;
	}
	return (min_value);
}
