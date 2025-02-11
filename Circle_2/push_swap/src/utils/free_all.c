/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:31:58 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 14:49:51 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_node(t_list *head)
{
	t_list	*temp;
	t_list	*first;

	first = head;
	while (head)
	{
		temp = head;
		if (head->next != first)
		{
			head = head->next;
			free(temp);
		}
		else
			break ;
	}
	free(head);
}

void	free_split(char **str)
{
	size_t	i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			free(str[i]);
			++i;
		}
	}
	if (str)
		free(str);
}

void	free_all(int ac, char **av, t_list *stack_a)
{
	(void)ac;
	free_split(av);
	free_node(stack_a);
}
