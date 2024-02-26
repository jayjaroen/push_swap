/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:32:25 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/26 14:33:29 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_up(t_node **list) //the first element become last one
{
	if (!(*list) || (*list)->next == NULL)
		return ;
	*list = (*list)->previous;
}

void	ft_rotate_down(t_node **list)
{
	if(!(*list) || (*list)->next == NULL)
		return ;
	*list = (*list)->next;
}

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
