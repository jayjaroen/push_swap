/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:13:37 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/16 22:02:06 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	size_t			index;
	size_t			cost;
	bool			above_median;
	bool			is_cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*previous;
} t_node;

typedef struct s_stack
{
	char 	name;
	t_node	*head;//the top node
	t_node	*max;
	t_node	*min;
	t_node	*cheapest;
	size_t	n;//stack size of a && b
} t_stack;

// operations to be change later
void	ft_add_node(t_node **list, t_node *new);
void	ft_swap(t_stack *stack, char c);
void	ft_rotate(t_stack *stack, char c);
void	ft_rotate_reverse(t_stack *stack, char c);
void    ft_push(t_stack *stack_out, t_stack *stack_in, char out);
void	ft_push_a(t_stack *a, t_stack *b);

// functions to create a node
void	ft_add_node(t_node **list, t_node *new);

// functions to create a list
void	ft_print_output(t_node *list, char *func);
void	ft_free_node(t_node **list);
void	ft_add_list_back(t_stack *list, int i);
void	ft_add_list_back_node(t_node **list, int i);
t_node	*ft_extract_node(t_node **list);

// functions to check agruments
int	ft_check_argv(int argc, char **argv);
int	ft_is_valid(char *argv);
int	ft_check_dup(char **argv, int argc);/// test

//functions to sort stacks
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_three(t_stack *stack);

//Node Utility functions
int	ft_count_node(t_node *list);
bool	ft_is_sorted(t_node *head);
t_node    *ft_finding_max(t_node **head);
t_node  *ft_finding_min(t_node **head);

//Stack Utility
void	ft_add_list_back(t_stack *stack, int i);

//stack initiation utility
void	ft_init_stack_a(t_stack *stack_a, t_stack *stack_b);
void	ft_init_stack_b(t_stack *stack_a, t_stack *stack_b);
void	ft_find_index(t_node **head);
void	ft_set_target_a(t_stack *a, t_stack *b);
void	ft_set_target_b(t_stack *a, t_stack *b);

//cost analysis
void	ft_cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest_cost(t_stack *stack);

//moving stacks
void	ft_rotate_both(t_stack *a, t_stack *b);
void	ft_reverse_rotate_both(t_stack *a, t_stack *b);
void	ft_check_cheapest_top(t_stack *stack, t_node *current_cheapest, char c);
void	ft_check_target_top(t_stack *stack, t_node *current_target, char c);
void	move_a_to_b(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack *a, t_stack *b);
void    ft_check_min_top(t_stack *a);

#endif
