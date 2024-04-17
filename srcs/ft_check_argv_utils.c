/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:09:26 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/17 15:21:34 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// what this function is going to do
// 1. Alpha or number
// 2. if number return
// 3. if not then, moving to split the word (characters)
// 4. Duplicate number is not allow
// 5. split the string arguments into words
// 6. convert the argument from string to int atoi
// 7. add the list to node

int	ft_atol(const char *str, bool *valid)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX || (result - 1 >= INT_MAX && sign == -1))
		{
			*valid = false;
			return (0);	
		}
		str++;
	}
	if (*str)
	{
		*valid = false;
		return (0);
	} 
	return (result * sign);
}

bool	ft_check_dup(t_stack *stack, int num)
{
	t_node	*current;
	t_node	*a;
	int		i;
	int		j;
	bool	result;

	a = stack->head;
	current = NULL;
	i = -1;
	result = true;
	while (++i < num)
	{
		j = i;
		current = a->next;
		while (++j < num)
		{
			if (a->value == current->value)
				return (result);
			current = current->next;
		}
		a = a->next;
	}
	return (false);
}
