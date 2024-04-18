/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:32:25 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/18 13:17:29 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_reverse(t_stack *stack, char c)
{
	if (stack->head && stack->n > 1)
		stack->head = stack->head->previous;
	if (c)
		ft_printf("rr%c\n", c);
}

void	ft_rotate(t_stack *stack, char c)
{
	if (stack->head && stack->n > 1)
		stack->head = stack->head->next;
	if (c)
		ft_printf("r%c\n", c);
}

void	ft_swap(t_stack *stack, char c)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	if (!stack)
		return ;
	tmp_a = stack->head;
	tmp_b = stack->head->next;
	tmp_a->next = tmp_b->next;
	tmp_b->next = tmp_a;
	tmp_a->next->previous = tmp_a;
	tmp_b->previous = tmp_a->previous;
	tmp_a->previous = tmp_b;
	tmp_b->previous->next = tmp_b;
	stack->head = tmp_b;
	ft_printf("s%c\n", c);
}

void	ft_push(t_stack *stack_out, t_stack *stack_in, char out)
{
	t_node	*extract;

	extract = ft_extract_node(&stack_out->head);
	ft_add_node(&stack_in->head, extract);
	stack_in->head = extract;
	stack_out->n -= 1;
	if (stack_in->n == 0)
	{
		stack_in->min = extract;
		stack_in->max = extract;
	}
	else
	{
		if (stack_in->min->value > extract->value)
			stack_in->min = extract;
		if (stack_in->max->value < extract->value)
			stack_in->max = extract;
	}
	stack_in->n += 1;
	if (extract->value == stack_out->max->value)
		stack_out->max = ft_finding_max(&stack_out->head);
	if (extract->value == stack_out->min->value)
		stack_out->min = ft_finding_min(&stack_out->head);
	ft_printf("p%c\n", out);
}

///////////////-----------previous--------/////////////////////////////////////

// void	ft_rotate(t_node **list) //the first element become last one
// {
// 	if (!(*list) || (*list)->next == NULL)
// 		return ;
// 	*list = (*list)->previous;
// }

// void	ft_rotate_reverse(t_node **list)
// {
// 	if(!(*list) || (*list)->next == NULL)
// 		return ;
// 	*list = (*list)->next;
// }

// void	ft_swap(t_node **list)//previous
// {
// 	t_node	*a;
// 	t_node	*b;
// /// need to thinking about the only one node // two nodes///
// 	if ((*list) -> next == NULL)
// 		return ;
// 	if ((*list) -> next == *list)
// 	{
// 		*list = (*list)->next; \
// 		return ;
// 	}
// 	a = *list;
// 	b = (*list)->next;
// 	a->next = b->next;
// 	b->next = a;
// 	a->next->previous = a;
// 	b->previous = a->previous;
// 	a->previous = b;
// 	b->previous->next = b; // closing the circular loop
// 	*list = b;
// }