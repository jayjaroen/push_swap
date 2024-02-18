/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:57:07 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/18 17:25:57 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (sign * num);
}

typedef struct s_stack
{
	int				value;
	struct s_stack	*next; //storing the address of the previous node
	struct s_stack	*previous; //storing the address of the last node
}	t_stack;

void	ft_add_to_stack(char *argv, t_stack **a)
{
	t_stack	*new;
	t_stack *ptr;
	
	if (!argv)
		return ;
	ptr = *a; // not changing to the stack a
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new -> value = ft_atoi(argv);
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;	
// implementing double / singular --> circulate 
}

t_stack	*ft_add_first(char *argv)
{
	t_stack	*first;
	
	first = malloc(sizeof(t_stack));
	if (first == NULL)
		return (NULL);
	first -> value = ft_atoi(argv);
	first -> next = NULL;
	return (first);
}

void	ft_print_stack(t_stack **stack)
{
	t_stack	*print_stack;

	print_stack = *stack;
	while (print_stack != NULL)
	{
		printf("%d\n", print_stack -> value);
		print_stack = print_stack -> next;
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	int		i;
	
	if (argc < 3 || !argv[1][0])
		return (1);
	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		if (stack_a == NULL)
			stack_a = ft_add_first(argv[i]);
		else
			ft_add_to_stack(argv[i], &stack_a);
		i++;	
	}
	ft_print_stack(&stack_a);
}