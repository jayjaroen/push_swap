/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:27 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/30 15:52:59 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_add_list_back(t_stack *stack, int i)
{
	t_node	*new;
	t_node 	*head;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		ft_free_node(&stack->head); //double pointer >reference of address of head is a double pointer
		return ;
	}

	//need to free after --> error hand - check stack a & b
	head = stack->head;
	new -> value = i;
	/// first node ////
	if (head == NULL)
	{
		new -> previous = NULL;
		new -> next = NULL;
		stack->head = new;
		stack->min = new;
		stack->max = new;
	}
	else if (head->next == NULL) // only two node in the stack
	{
		new -> next = head;
		new -> previous = head;
		head -> previous = new;
		head -> next = new;
		if (new->value > stack->max->value)
			stack->max = new;
		if (new->value < stack->min->value)
			stack->min = new;
	}
	else
	{
		new -> next = head;
		new -> previous = head -> previous;
		new -> previous -> next = new; // update the last node of the list
		head -> previous = new;
		if (new->value > stack->max->value)
			stack->max = new;
		if (new->value < stack->min->value)
			stack->min = new;
	}
	stack->n += 1; //size of stack every time adding the new node 
}