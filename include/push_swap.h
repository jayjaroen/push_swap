/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:13:37 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/30 17:13:51 by jjaroens         ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*previous;
 
	
} t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*max;
	t_node	*min;
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
void	ft_swap(t_node **list);
void	ft_rotate(t_node **list);
void	ft_rotate_reverse(t_node **list);
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

//Stack Utility 
void	ft_add_list_back(t_stack *stack, int i);

#endif
