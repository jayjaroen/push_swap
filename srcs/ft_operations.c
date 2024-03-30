/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:32:25 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/30 17:32:18 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* This file contains functions that move the element within the stack*/
//the first element become last one (ra, rb)

void	ft_rotate(t_node **list) //the first element become last one
{
	if (!(*list) || (*list)->next == NULL)
		return ;
	*list = (*list)->previous;
}

//the last element become the first one (rra, rrb)
void	ft_rotate_reverse(t_node **list)
{
	if(!(*list) || (*list)->next == NULL)
		return ;
	*list = (*list)->next;
}

// swap the position between the first top two elements
// sa, sb
void	ft_swap(t_node **list)
{
	t_node	*a;
	t_node	*b;
/// need to thinking about the only one node // two nodes///
	if ((*list) -> next == NULL)
		return ;
	if ((*list) -> next == *list)
	{
		*list = (*list)->next; //looping condition already set at the previous function
		return ;
	}
	a = *list;
	b = (*list)->next;
	a->next = b->next;
	b->next = a;
	a->next->previous = a;
	b->previous = a->previous;
	a->previous = b;
	b->previous->next = b; // closing the circular loop
	*list = b;
	// b->previous = a;
	// a->previous = b;
	// a->next = b->next;
	// b->previous = a->previous;
	// b->previous->next = b;
}

void    ft_push(t_stack *stack_out, t_stack *stack_in, char out)
{
	//// also need to update min max after push, change the stack////
	t_node	*extract;

	extract = ft_extract_node(&stack_out->head);
	// ft_update_info(stack_a, extract);
	ft_add_node(&stack_in->head, extract);
	stack_in->head = extract;
	stack_out->n -= 1;
	stack_in->n += 1;
	//setting min && max
	ft_printf("p%c\n", out);
	ft_printf("hi there head_b: %p, \n", stack_in->head);
}