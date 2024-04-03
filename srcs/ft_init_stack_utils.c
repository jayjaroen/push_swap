/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:10:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/03 22:53:04 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_find_index(t_node **head)
{
	t_node	*current;
	int		i;
	int		median;

	// if (!head)
	// 	return ;
	current = *head;
	i = 0;
	median = ft_count_node(*head)/2;
	while (1)
	{
        ft_printf("I am inside the loop of ft_index\n");
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

void	ft_set_target_a(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target_b;
	long	best_match;

	current_a = *a;
	current_a->previous->next = NULL;
	while (current_a != NULL)
	{
		best_match = LONG_MIN;
		current_b = *b;
		current_b->previous->next = NULL;
		while (current_b)
		{
			if (current_b->value > current_a->value && //should be bigger
			current_b->value > best_match)
			{
				best_match = current_b->value;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			current_a->target_node = ft_finding_min(b);
		else
			current_a->target_node = target_b;
		current_a = current_a->next;
	}
}
