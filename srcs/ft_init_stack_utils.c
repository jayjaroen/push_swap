/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:10:59 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/02 22:38:00 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	ft_find_index(t_node **head)
{
	t_node	*current;
	int		i;
	int		median;

	if (!head)
		return ;
	current = *head;
	i = 0;
	median = ft_count_node(*head)/2;
	while (1)
	{
		current->index = i++;
		if (current->index <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		if (current == *head)
			break ;
	}
}
