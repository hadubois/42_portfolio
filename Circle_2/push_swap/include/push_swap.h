/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:30:02 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/25 15:03:37 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>

typedef struct t_list
{
	int				value;
	struct t_list	*next;
	struct t_list	*prev;
}	t_list;

//ALGORITHM
void	push_swap(t_list **a, t_list **b);

//MOVES
void	push_in(char stack, t_list **dest, t_list **src);
void	reverse_rotate(char stack, t_list **list);
void	rotate(char stack, t_list **list);
void	swap(char stack, t_list **list);
void	rrr(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);

//UTILS
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char const *set);
char	**ft_split(char const *s, char c);
//
int		test_args(char **av);
//
long	ft_atol(const char *nptr);
//
size_t	ft_strlen(const char *str);

//CHAIN_LIST_UTILS
int		find_max_in_chunk(t_list *list, int chunk);
int		lowest_cost(t_list *dest, t_list *src);
int		find_cible_in(t_list *dest, int value);
int		find_cible(t_list *list, int value);
int		find_min_value_in(t_list *list);
int		find_max_value_in(t_list *list);
int		is_sort(t_list *list);
void	print_single_list(t_list *head, char side);
int		is_int(char *str);
//
void	do_best_move(int value, t_list **dest, t_list **src);
void	put_on_top_of(char s, t_list **list, int value);
void	free_all(int ac, char **av, t_list *stack_a);
void	print_lists(t_list *a, t_list *b);
void	free_node(t_list *head);
void	free_split(char **str);
void	sort_three_args_in_a(t_list **a);
//
size_t	find_index_of(int value, t_list *list);
size_t	size_of(t_list *head);
size_t	middle(t_list *list);
t_list	*fill_stack(size_t ac, char **av);
t_list	*fill_stack_bis(char **av, t_list *head);

#endif
