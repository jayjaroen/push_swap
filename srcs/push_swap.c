/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:09:27 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/17 23:17:21 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_write_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	ft_free_error(char **ptr)
{
	ft_free_split(ptr);
	ft_write_error();
}

void    push_swap(char **argv, int argc, t_stack *stack_a, int *result)
{
    char    **str;
    char    **ptr;
    int     i;
	bool	valid;

	i = 0;
	valid = true;
    while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		ptr = str;
		while (*str != (void *)0)
		{
			*result = ft_atol(*str, &valid);
			if (valid == false)
			{
				if (stack_a->head != NULL)
					ft_free_node(&stack_a->head);
				ft_free_error(ptr);
			}
			ft_add_list_back(stack_a, *result);
			str++;
		}
		ft_free_split(ptr);
    }
}
