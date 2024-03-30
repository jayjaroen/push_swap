/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:27:08 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/30 16:47:47 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	ft_print_output(t_node *list)
{
	t_node	*head;

	if (!list)
		return ;
	head = list;
	// ft_printf("the address of ptr: %p\n", head);
	// ft_printf("the address of ptr -> next: %p\n", head->next);
	// ft_printf("the refer of function: %p\n", &list);
	while (1)
	{
		ft_printf("addr: %p,  %d\n", list, list->value);
		if (!list->next)
			break ;
		list = list->next;
		if (list == head)
			break;
	}
}
