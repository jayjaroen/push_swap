/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_between_stacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:46:47 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/08 11:59:20 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_check_target_top(t_stack *stack, t_node *current_target, char c)
{
	ft_printf("I am ft_check_target\n");
	ft_printf("stack: %c, stack->head: %d, current_target: %d\n", stack->name,
	 stack->head->value, current_target->value);
	if (stack->head == current_target)
		return ;
	while (stack->head != current_target)
	{
		if (current_target->above_median)
		{
			ft_rotate(stack);
			ft_printf("r%c\n", c);
		}
		else if (!current_target->above_median)
		{
			ft_rotate_reverse(stack);
			ft_printf("r%c\n", c);
		}
	}	
}

void	ft_check_cheapest_top(t_stack *stack, t_node *current_cheapest, char c)
{
	ft_printf("I am ft_check_top\n");
	ft_printf("stack: %c, stack->head: %d, current_cheapest: %d\n",
		stack->name, stack->head->value, current_cheapest->value);
	if (stack->head == current_cheapest)
		return ;
	while (stack->head != current_cheapest)
	{
		if (stack->cheapest->above_median)
		{
			ft_printf("r%c\n", c);
			ft_rotate(stack);
		}
		else if (!stack->cheapest->above_median)
		{
			ft_printf("rr%c\n", c);
			ft_rotate_reverse(stack);
		}
	}
}
void	ft_rotate_both(t_stack *a, t_stack *b)
{
	ft_printf("I am ft_rotate_both\n");
	while (a->head != a->cheapest && b->head != a->cheapest->target_node)
	{
		ft_rotate(a);
		ft_rotate(b);
		ft_printf("rr\n");
	}
	// ft_find_index(a->head);
	// ft_find_index(b->head);
}

void	ft_reverse_rotate_both(t_stack *a, t_stack *b)
{
	while (a->head != a->cheapest && b->head != a->cheapest->target_node)
	{
		ft_printf("I am ft_reverse_rotate_both\n");
		ft_rotate_reverse(a);
		ft_rotate_reverse(b);
		ft_printf("rrr\n");
	}
	// ft_find_index(a->head);// find index once we do the loop again?
	// ft_find_index(b->head);	
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	ft_printf("I am a move_a_to_b function\n");
	if (a->cheapest->above_median && a->cheapest->target_node->above_median)
		ft_rotate_both(a,b);
	else if ((!a->cheapest->above_median) && 
		(!a->cheapest->target_node->above_median))
		ft_reverse_rotate_both(a, b);
	ft_check_cheapest_top(a, a->cheapest, 'a');
	ft_check_target_top(b, a->cheapest->target_node, 'b');
	ft_push(a, b, 'b');
	ft_printf("I am about to leave move_a_to_b function\n");
}