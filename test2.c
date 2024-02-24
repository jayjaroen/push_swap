/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:49:10 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/24 21:53:03 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/////// Libft //////
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
///////////////////////// dealing with stack //////////////////////////
typedef struct s_stack
{
	int				value;
	struct s_stack	*next; //storing the address of the previous node
	struct s_stack	*previous; //storing the address of the last node
}	t_stack;


t_stack	*add_first_node(char *argv, t_stack **tail)
{
	t_stack	*first;

	first = malloc(sizeof(t_stack));
	if (!first)
		return (NULL);
	first -> value = ft_atoi(argv);
	first -> next = first; // circular link list
	first -> previous = first;
	(*tail) -> next = first;
	*tail = first;
	return (first);
}

void	add_to_stack_back(char *argv,t_stack *stack, t_stack *tail)
{
	t_stack	*new;
	t_stack *tmp;

	if (!argv)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	tmp = tail -> next;
	new -> value = ft_atoi(argv);
	new -> next = tmp;
	new -> previous = tail -> next;
	tail -> next = tmp;
	tail = new;
}

void	ft_print_stack_ascend(t_stack *stack, t_stack *tail)
{
	t_stack *tmp;

	tmp = stack;
	printf("the ascending order: ");
	while (tmp != tail -> next)
	{
		printf("%d\n", tmp -> value);
		tmp = tmp -> next;
	}
}

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_stack *tail;
	int		i;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	tail = NULL;
	i = 1;
    printf("hello world\n");
	while (argv[i]) // need to edit later
	{
		printf("am i here?");
		if (stack_a == NULL)
			stack_a = add_first_node(argv[i], &tail);
		else
			add_to_stack_back(argv[i], stack_a, tail);
		i++;
		printf(" am i here");
	}
	ft_print_stack_ascend(stack_a, tail);
	return (0);
}
