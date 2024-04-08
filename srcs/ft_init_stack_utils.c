/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:10:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/08 11:25:38 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_find_index(t_node **head)
{
	t_node	*current;
	size_t	i;
	size_t	median;

	// if (!head)
	// 	return ;
	current = *head;
	i = 0;
	if (ft_count_node(*head) == 2)
		median = 1;
	else
		median = ft_count_node(*head)/2;
	while (1)
	{
		current->index = i;
		if (current->index <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
        i++;
		if (current == *head)
			break ;
	}
}

void	ft_set_target_a(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target_b;
	long	best_match;
	size_t	index_a;
	size_t	index_b;

	current_a = a->head;
    ft_printf("I am inside of the init stack function!\n");
	index_a = -1;
	while (++index_a < a->n)
	{
		best_match = LONG_MIN;
		current_b = b->head;
        target_b = NULL;
		index_b = -1;
		// current_b->previous->next = NULL;
        ft_printf("the number of current is: %d\n", current_a->value);
		while (++index_b < b->n)
		{
            ft_printf("inside the b loop\n");
			if ((current_b->value < current_a->value) &&
			(current_b->value > best_match))
			{
				best_match = current_b->value;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
        ft_printf("am I here?\n");
		if (best_match == LONG_MIN)
			current_a->target_node = ft_finding_max(&b->head);
		else
			current_a->target_node = target_b;
		ft_printf("target node of A is: %d\n", current_a->target_node->value);
		current_a = current_a->next;
		ft_printf("hi there\n");
	}
}

// The steps for A to be on top and the target node to be on top
void	ft_cost_analysis_a(t_stack *a, t_stack *b)
{
	size_t	index;
	t_node	*current_a;

	index = -1;
	current_a = a->head;
	while (++index < a->n)
	{
		current_a->cost = current_a->index;
		if (!current_a->above_median)
			current_a->cost = a->n - current_a->index;
		if (current_a->target_node->above_median)
			current_a->cost += current_a->target_node->index;
		else
			current_a->cost += b->n - current_a->target_node->index;
		ft_printf("the cost of a: %d is %d\n", current_a->value, current_a->cost);
		current_a = current_a->next;
	}
}

void	set_cheapest_cost(t_stack *stack)
{
	t_node	*current_node;
	// t_node	*cheapest_node;
	unsigned long	cheapest_value;
	size_t	index;

	if (!stack)
		return ;
	current_node = stack->head;
	cheapest_value = LONG_MAX;
	index = -1;
	while (++index < stack->n)
	{
		if (current_node->cost < cheapest_value)
		{
			cheapest_value = current_node->cost;
			stack->cheapest = current_node;
			current_node->is_cheapest = true;
		}
		current_node = current_node->next;
	}
	// cheapest_node->is_cheapest = true;
	// stack->cheapest = cheapest_node;
	ft_printf("the cheapest node to push is: %d\n", stack->cheapest->value);
}
