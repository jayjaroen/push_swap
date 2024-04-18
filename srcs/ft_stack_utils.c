/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:27 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/18 13:39:41 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_nodes(t_stack *stack, t_node *new, t_node *head)
{
	new -> next = head;
	new -> previous = head -> previous;
	new -> previous -> next = new;
	head -> previous = new;
	if (new->value > stack->max->value)
		stack->max = new;
	if (new->value < stack->min->value)
		stack->min = new;
}

void	ft_set_next_node(t_stack *stack, t_node *new, t_node *head)
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

void	ft_set_head_node(t_stack *stack, t_node *new)
{
	new -> previous = NULL;
	new -> next = NULL;
	stack->head = new;
	stack->min = new;
	stack->max = new;
}

void	ft_add_list_back(t_stack *stack, int i)
{
	t_node	*new;
	t_node	*head;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		ft_free_node(&stack->head);
		return ;
	}
	head = stack->head;
	new -> value = i;
	if (head == NULL)
		ft_set_head_node(stack, new);
	else if (head->next == NULL)
		ft_set_next_node(stack, new, head);
	else
		ft_set_nodes(stack, new, head);
	stack->n += 1;
}
