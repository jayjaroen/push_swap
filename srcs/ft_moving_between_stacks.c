/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_between_stacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:46:47 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/17 16:50:44 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_check_target_top(t_stack *stack, t_node *current_target, char c)
{
	// ft_printf("I am ft_check_target\n");
	// ft_printf("stack: %c, stack->head: %d, current_target: %d\n", stack->name,
	//  stack->head->value, current_target->value);
	if (stack->head == current_target)
		return ;
	while (stack->head != current_target)
	{
		if (current_target->above_median)
			ft_rotate(stack, c);
		else if (!current_target->above_median)
			ft_rotate_reverse(stack, c);
	}	
}

void	ft_check_cheapest_top(t_stack *stack, t_node *current_cheapest, char c)
{
	// ft_printf("I am ft_check_top\n");
	// ft_printf("stack: %c, stack->head: %d, current_cheapest: %d\n",
	// 	stack->name, stack->head->value, current_cheapest->value);
	if (stack->head == current_cheapest)
		return ;
	while (stack->head != current_cheapest)
	{
		if (stack->cheapest->above_median)
			ft_rotate(stack, c);
		else if (!stack->cheapest->above_median)
			ft_rotate_reverse(stack, c);
	}
}
void	ft_reverse_rotate_both(t_stack *a, t_stack *b)
{
	while (a->head != a->cheapest && b->head != a->cheapest->target_node)
	{
		ft_rotate_reverse(a, 0);
		ft_rotate_reverse(b, 0);
		ft_printf("rrr\n");
	}
}

void	ft_rotate_both(t_stack *a, t_stack *b)
{
	while (a->head != a->cheapest && b->head != a->cheapest->target_node)
	{
		ft_rotate(a, 0);
		ft_rotate(b, 0);
		ft_printf("rr\n");
	}
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	if (a->cheapest->above_median && a->cheapest->target_node->above_median)
		ft_rotate_both(a,b);
	else if ((!a->cheapest->above_median) && 
		(!a->cheapest->target_node->above_median))
		ft_reverse_rotate_both(a, b);
	ft_check_cheapest_top(a, a->cheapest, 'a');
	ft_check_target_top(b, a->cheapest->target_node, 'b');
	ft_push(a, b, 'b');
}