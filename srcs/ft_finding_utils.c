/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:50:44 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/01 21:51:05 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

t_node    *ft_finding_max(t_node **head)
{
    t_node  *max;
	t_node *current;

	current = *head;
	max = current;
	while (1)
	{
		if (current->next->value > max->value)
			max = current->next;
		current = current->next;
		if (current == *head)
			break ;
	}
	return (max);
}

t_node  *ft_finding_min(t_node **head)
{
    t_node  *min;
	t_node	*current;

	min = *head;
	current = *head;

	while (1)
	{
		if (current->next->value < min->value)
			min = current->next;
		current = current->next;
		if (current == *head)
			break ;
	}
	return (min);
}
