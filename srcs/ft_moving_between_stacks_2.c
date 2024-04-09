/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_between_stacks_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:51:20 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/09 21:55:52 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	move_b_to_a(t_stack *a, t_stack *b)
{
	ft_printf("I am a move_b_to_a function\n");
	ft_find_index(&a->head);
	ft_check_target_top(a, b->head->target_node, 'a');
	ft_printf("am I here in move_b_to_a\n");
	ft_push_a(a, b);
	ft_printf("am I here after ft_push???\n");
}

void	ft_push_a(t_stack *a, t_stack *b)
{
	t_node	*extract;

	ft_printf("I am inside ft_push_a\n");
	extract = ft_extract_node(&b->head);
	ft_add_node(&a->head, extract);
	a->head = extract;
	b->n -= 1;
	a->n += 1;
	if (extract->value > a->max->value)
		a->max = extract;
	if (extract->value < a->min->value)
		a->min = extract;
	ft_printf("pa\n");
}

void	ft_check_min_top(t_stack *a)
{
	while (a->head != a->min)
	{
		if (a->min->above_median)
			ft_rotate(a, 'a');
		else if (!a->min->above_median)
			ft_rotate_reverse(a, 'a');
	}
}
