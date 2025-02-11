/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:44:06 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 15:03:07 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_list	*ft_create_node(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

static t_list	*ft_add_at_end(t_list *head, int value)
{
	t_list	*new_node;
	t_list	*current;
	t_list	*first;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (head);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!head)
		return (new_node);
	current = head;
	first = head;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->next == first)
			break ;
	}
	current->next = new_node;
	new_node->prev = current;
	head->prev = new_node;
	new_node->next = head;
	return (head);
}

int	is_in_list(int value, t_list *head)
{
	t_list	*first;

	first = head;
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
		if (head == first)
			break ;
	}
	return (0);
}

t_list	*fill_stack_bis(char **av, t_list *head)
{
	int		i;

	i = 0;
	if (!head)
	{
		if (!is_int(av[i]))
			return (NULL);
		head = ft_create_node(ft_atol(av[i]));
		if (!head)
			return (NULL);
		i++;
	}
	while (av[i])
	{
		if (!is_int(av[i]) || is_in_list(ft_atol(av[i]), head))
			return (free_node(head), NULL);
		ft_add_at_end(head, ft_atol(av[i]));
		++i;
	}
	return (head);
}
