/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:18:48 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/17 13:57:53 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	ft_sort_three(t_stack *stack)
{
	if (stack->head == stack->max)
    {
		ft_rotate_reverse(stack, 'a');
		if (stack->head->next == stack->min)
			ft_swap(stack, 'a');
    }
	else if (stack->head == stack->min)
	{
		if (stack->head->next == stack->max)
		{
			ft_rotate(stack, 'a');
			ft_swap(stack, 'a');
		}
	}
	else
	{
		if (stack->head->next == stack->max)
			ft_rotate(stack, 'a');
		else if (stack->head->next == stack->min)
			ft_swap(stack, 'a');
	}
}

void	ft_sort_large(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->n > 3 && !ft_is_sorted(stack_a->head))
		ft_push(stack_a, stack_b, 'b');
	if (stack_a->n > 3 && !ft_is_sorted(stack_a->head))
		ft_push(stack_a, stack_b, 'b');
    while (stack_a->n > 3 && !ft_is_sorted(stack_a->head))
    {
        ft_init_stack_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
    }
	ft_sort_three(stack_a);
	while (stack_b->n > 0)
	{
		ft_init_stack_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
    ft_find_index(&stack_a->head);
	ft_check_min_top(stack_a);
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a->head))
		return ;
	else if (stack_a->n == 2)
		ft_swap(stack_a, 'a');
	else if (stack_a->n == 3)
		ft_sort_three(stack_a);
	else if (stack_a->n > 3)
		ft_sort_large(stack_a, stack_b);
}

bool	ft_is_sorted(t_node *head)
{
	t_node	*ptr;

	ptr = head;
	if (ptr->next == NULL)
		return (0);
	while (ptr->next != head)
	{
		if (ptr->value >= ptr->next->value)
			return (false);
		ptr = ptr->next;
	}
	return (true);
}
