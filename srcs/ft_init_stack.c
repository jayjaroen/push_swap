/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:04:18 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/05 14:19:58 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_find_index(&stack_a->head);//finding the index
    ft_find_index(&stack_b->head);
    ft_set_target_a(&stack_a->head, &stack_b->head); // this function still have seg fault
}
