/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:19:09 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 15:23:35 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	int	next_move;
	int	median;

	median = find_max_in_chunk(*a, size_of(*a) / 2);
	while (size_of(*a) > 3)
	{
		push_in('b', b, a);
		if ((*b)->value < median)
			rotate('b', b);
	}
	sort_three_args_in_a(a);
	while (*b)
	{
		next_move = lowest_cost(*a, *b);
		do_best_move(next_move, a, b);
	}
	put_on_top_of('a', a, find_min_value_in(*a));
}

void	handle_errors(char **temp, t_list *stack_a, int state)
{
	if (state == 1 && !temp)
		exit(write(2, "Error\n", 6));
	if (state == 1 && temp && !temp[0])
		exit(write(2, "Error\n", 6));
	if (state == 2 && !stack_a)
	{
		free_split(temp);
		exit(write(2, "Error\n", 6));
	}
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**temp;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (EXIT_SUCCESS);
	i = 1;
	while (av[i])
	{
		temp = ft_split(av[i], ' ');
		handle_errors(temp, stack_a, 1);
		if (!test_args(temp))
			return (free_split(temp), write(1, "Error\n", 6), EXIT_FAILURE);
		stack_a = fill_stack_bis(temp, stack_a);
		handle_errors(temp, stack_a, 2);
		free_split(temp);
		i++;
	}
	if (!is_sort(stack_a))
		push_swap(&stack_a, &stack_b);
	free_node(stack_a);
	return (EXIT_SUCCESS);
}
