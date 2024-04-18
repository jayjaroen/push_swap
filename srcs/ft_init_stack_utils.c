/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:10:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/18 12:26:57 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_find_index(t_node **head)
{
	t_node	*current;
	size_t	i;
	size_t	median;

	if (!head)
		return ;
	current = *head;
	i = 0;
	median = ft_count_node(*head) / 2;
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

void	ft_set_target_b(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	long	best_match;
	size_t	index_a;
	size_t	index_b;

	current_b = b->head;
	index_b = -1;
	while (++index_b < b->n)
	{
		best_match = LONG_MAX;
		current_a = a->head;
		index_a = -1;
		while (++index_a < a->n)
		{
			set_best_match_b(current_a, current_b, &best_match);
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			current_b->target_node = ft_finding_min(&a->head);
		current_b = current_b->next;
	}
}

void	ft_set_target_a(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	long	best_match;
	size_t	index_a;
	size_t	index_b;

	current_a = a->head;
	index_a = -1;
	while (++index_a < a->n)
	{
		best_match = LONG_MIN;
		current_b = b->head;
		index_b = -1;
		while (++index_b < b->n)
		{
			set_best_match_a(current_a, current_b, &best_match);
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			current_a->target_node = ft_finding_max(&b->head);
		current_a = current_a->next;
	}
}

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
		current_a = current_a->next;
	}
}

void	set_cheapest_cost(t_stack *stack)
{
	t_node			*current_node;
	unsigned long	cheapest_value;
	size_t			index;

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
}
