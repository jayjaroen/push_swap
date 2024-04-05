/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:10:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/05 22:15:27 by jjaroens         ###   ########.fr       */
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
    ft_printf("I am inside of the init stack function!\n");
	while (current_a)
	{
		best_match = LONG_MIN;
		current_b = *b;
        target_b = NULL;
		current_b->previous->next = NULL;
        ft_printf("the number of current is: %d\n", current_a->value);
		while (current_b)
		{
            ft_printf("inside the b loop\n");
			if ((current_b->value < current_a->value) &&
			(current_b->value > best_match))
			{
				best_match = current_b->value;
				target_b = current_b;
			}
			current_b = current_b->next;
            // if (current_b == *b)
            //     break ;
		}
        ft_printf("am I here?\n");
		if (best_match == LONG_MIN)
			current_a->target_node = ft_finding_max(b);
		else
			current_a->target_node = target_b;
		current_a = current_a->next;
        ft_printf("hi there\n");
        // ft_printf("the target of A node in B is:%d\n", current_a->target_node);
	}
}
