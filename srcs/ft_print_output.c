/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:27:08 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/17 13:53:57 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	ft_print_output(t_node *list, char *func)
{
	t_node	*head;

	if (!list)
		return ;
	head = list;
	ft_printf ("-- all node debug from: %s --\n", func);
	while (list)
	{
		ft_printf("addr: %p,  %d\n", list, list->value);
		if (!list->next || list->next == head)
			break ;
		list = list->next;
	}
}
