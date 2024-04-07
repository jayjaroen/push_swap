/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:13:37 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/07 17:41:21 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <unistd.h> //write
// # include <stdlib.h>
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
	t_node	*head;//the top node
	t_node	*max;
	t_node	*min;
	t_node	*cheapest;
	size_t	n;//stack size of a && b
} t_stack;

// typedef	struct s_data //stack A && stack B each has t_data
// {
// 	int		value_diff;
// 	int		number_of_moves;
// 	int		current_index; //update after rotate || compare the the median
// 	t_node	*target_node;
// } t_data; // associate for each node A & B (of each particular node)


// heap && stack --> main function
// malloc --> using memory of heap

// submodule to the library? / Make file

/*Handling the list of the agruments -> create a node of arguments and add
to the list*/

// operations to be change later
void	ft_add_node(t_node **list, t_node *new);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_rotate_reverse(t_stack *stack);
void    ft_push(t_stack *stack_out, t_stack *stack_in, char out);

// functions to create a node
void	ft_add_node(t_node **list, t_node *new);

// functions to create a list
void	ft_print_output(t_node *list);
void	ft_free_node(t_node **list);
void	ft_add_list_back(t_stack *list, int i);
void	ft_add_list_back_node(t_node **list, int i);
t_node	*ft_extract_node(t_node **list);

// functions to check agruments
int	ft_check_argv(int argc, char **argv);
int	ft_is_valid(int argv);

//functions to sort stacks
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_small(t_stack *stack);

//Node Utility functions
int	ft_count_node(t_node *list);
bool	ft_is_sorted(t_node *head);
t_node    *ft_finding_max(t_node **head);
t_node  *ft_finding_min(t_node **head);

//Stack Utility
void	ft_add_list_back(t_stack *stack, int i);

//stack initiation utility
void	ft_init_stack_a(t_stack *stack_a, t_stack *stack_b);
void	ft_find_index(t_node **head);
void	ft_set_target_a(t_stack *a, t_stack *b);

//cost analysis
void	ft_cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest_cost(t_stack *stack);

//moving stacks
void	ft_rotate_both(t_stack *a, t_stack *b);
void	ft_reverse_rotate_both(t_stack *a, t_stack *b);
void	ft_check_top(t_stack *stack, t_node *current_cheapest, char c);
void	move_a_to_b(t_stack *a, t_stack *b);

#endif
