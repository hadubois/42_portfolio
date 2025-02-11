/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:57:22 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 11:43:02 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_single_list(t_list *head, char side)
{
	t_list	*first;

	if (!head)
		exit(write(2, "Error\n", 6));
	first = head;
	while (head)
	{
		if (side == 'a')
			printf("%3d |\n", head->value);
		else if (side == 'b')
			printf("    | %d\n", head->value);
		else
			printf("%3d\n", head->value);
		head = head->next;
		if (head == first)
			break ;
	}
}

static void	print_list_header(void)
{
	printf(" A  |  B \n");
	printf("¯¯¯¯¯¯¯¯¯\n");
}

static void	exeption_case(t_list *a, t_list *b)
{
	if (!a)
		return (print_single_list(b, 'b'));
	if (!b)
		return (print_single_list(a, 'a'));
}

void	print_lists(t_list *a, t_list *b)
{
	t_list	*first_a;
	t_list	*first_b;

	print_list_header();
	if (!a || !b)
		return (exeption_case(a, b));
	printf("%3d | %d\n", a->value, b->value);
	first_a = a;
	first_b = b;
	a = a->next;
	b = b->next;
	while (a != first_a || b != first_b)
	{
		if (a != first_a)
			printf("%3d | ", a->value);
		if (a != first_a)
			a = a->next;
		else
			printf("    | ");
		if (b != first_b)
			printf("%d", b->value);
		if (b != first_b)
			b = b->next;
		printf("\n");
	}
}
