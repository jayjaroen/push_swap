/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:18:48 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/10 21:05:59 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	ft_sort_three(t_stack *stack)
{
	// 3 2 1
	// 3 1 2
	if (stack->head == stack->max)
    {
		ft_rotate_reverse(stack, 'a');
		if (stack->head->next == stack->min)
			ft_swap(stack, 'a');
    }
	// 1 3 2
	else if (stack->head == stack->min)
	{
		if (stack->head->next == stack->max)
		{
			ft_rotate(stack, 'a');
			ft_swap(stack, 'a');
		}

	}
	// 2 3 1
	// 2 1 3
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
	ft_printf("I am a ft_sort_large!!\n");
	if (stack_a->n > 3 && !ft_is_sorted(stack_a->head))
		ft_push(stack_a, stack_b, 'b');
	if (stack_a->n > 3 && !ft_is_sorted(stack_a->head))
		ft_push(stack_a, stack_b, 'b');
    while (stack_a->n > 3 && !ft_is_sorted(stack_a->head))
    {
        ft_init_stack_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
    }
	ft_print_output(stack_a->head, "ft_sort_large");
	ft_sort_three(stack_a);
	ft_printf("the number of stack b: %d\n", stack_b->n);
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
	{
		ft_swap(stack_a, 'a');
		ft_printf("sa\n");//swap
	}
	else if (stack_a->n == 3)
		ft_sort_three(stack_a);
	else if (stack_a->n > 3)
		ft_sort_large(stack_a, stack_b);
    ft_printf("am i back here yet\n");
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
