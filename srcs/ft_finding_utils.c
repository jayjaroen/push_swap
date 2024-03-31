/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:50:44 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/31 22:59:15 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

t_node    *ft_finding_max(t_node **head)
{
    t_node  *max;
	t_node *current;

    ft_printf("hi there");
	max = *head;
	current = *head;
	while (1)
	{
		if (current->value < current->previous->value)
			max = current->previous;
		current = current->next;
		if (current == *head)
			break ;
	}
	ft_printf("the max node is %d\n", max->value);
	return (max);
}
