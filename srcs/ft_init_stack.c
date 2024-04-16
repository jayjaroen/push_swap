/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:04:18 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/10 21:06:20 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_find_index(&stack_a->head);
    ft_find_index(&stack_b->head);
    ft_set_target_a(stack_a, stack_b);
	ft_cost_analysis_a(stack_a, stack_b);
	set_cheapest_cost(stack_a);
}

void	ft_init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_find_index(&stack_a->head);
	ft_set_target_b(stack_a, stack_b);
}
