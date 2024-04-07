/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:18:48 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/07 17:42:13 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

// 1) sorting small stack (3)
// 2) sorting large stack ( more than 3)
// need to print out the operation
void	ft_sort_small(t_stack *stack)
{
    /// the highest number at the first position
	if (stack->n == 2)
	{
		ft_swap(stack);
		return ;
	}
	if (stack->head == stack->max)
    {
		ft_rotate_reverse(stack);
		ft_printf("%d\n", stack->head->value);
		if (stack->head->next == stack->min)
			ft_swap(stack);
		// 3 1 2
		// 3 2 1
    }
	// the lowest number at the first position
	else if (stack->head == stack->min)
	{
		if (stack->head->next < stack->head->previous)
		{
			ft_rotate(stack);
			ft_swap(stack);
		}
	}
	// the second highest number is at the first position
	else
	{
		if (stack->head->next == stack->max)
			ft_rotate(stack);
		else if (stack->head->next == stack->min)
			ft_swap(stack);
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
        ft_printf("about to start to initialize stack a\n");
        ft_init_stack_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
        break ;
    }
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	//before sort stack a --> need to prevent the error first
	//create another function
	if (ft_is_sorted(stack_a->head))
		return ;
	else if (stack_a->n <= 3) // 2 & 3
		ft_sort_small(stack_a);
	else if (stack_a->n > 3)
		ft_sort_large(stack_a, stack_b);
    ft_printf("am i back here yet");
}

// The following function is to see if the stack is sorted///
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
