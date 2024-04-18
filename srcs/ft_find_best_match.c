/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_match.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:59:11 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/18 12:24:45 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_best_match_b(t_node *a, t_node *b, long *best_match)
{
	if ((a->value > b->value) && (a->value < *best_match))
	{
		*best_match = a->value;
		b->target_node = a;
	}
}

void	set_best_match_a(t_node *a, t_node *b, long *best_match)
{
	if ((b->value < a->value) && (b->value > *best_match))
	{
		*best_match = b->value;
		a->target_node = b;
	}
}