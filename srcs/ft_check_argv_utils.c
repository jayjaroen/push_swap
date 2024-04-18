/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:09:26 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/18 11:43:53 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

bool	ft_is_valid(const char *str, bool *valid)
{
	if (*str)
	{
		if (*str != '\0')
			*valid = false;
		return (false);
	}
	return (true);
}

bool	ft_check_result_valid(long *result, bool *valid, int sign)
{
	if (*result > INT_MAX || (*result - 1 >= INT_MAX && sign == -1))
	{
		*valid = false;
		return (false);
	}
	return (true);
}

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
		if (!ft_check_result_valid(&result, valid, sign))
			return (0);
		str++;
	}
	if (!ft_is_valid(str, valid))
		return (0);
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
