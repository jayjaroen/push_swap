/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:04:18 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/06 15:01:24 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_find_index(&stack_a->head);//finding the index
    ft_find_index(&stack_b->head);
    ft_set_target_a(stack_a, stack_b);
	ft_cost_analysis_a(stack_a, stack_b);
}
