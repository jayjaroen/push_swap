/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:57:07 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/24 15:16:48 by jjaroens         ###   ########.fr       */
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

void	ft_add_to_stack(char *argv, t_stack *a, t_stack *head, t_stack *tail)
{
	t_stack	*new;
	t_stack *ptr;
	// if already have tail -- then don't need to loop ptr
	if (!argv)
		return ;
	ptr = a; // not changing to the stack a
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new -> value = ft_atoi(argv);
	new -> previous = tail -> previous;
	printf("this is tail: %p\n", new -> previous);
	printf("this is address of tail: %p\n", tail);
	new -> next = tail -> next;
	// tail = new;
    //Before code singled linked list
	// while (ptr -> next != NULL)
	// 	ptr = ptr -> next;
	// ptr -> next = new;
// implementing circular
// // If the only one node
// 	if (ptr -> next == ptr) // why can't use a -> next // the only node
// 	{
// 		new -> previous = new; // circular pointing to itself
// 		new -> next = new;
// 	}
// 	else
// 	{
// 		new -> previous = tail; //tail the last node
// 		new -> next = head;
// 	}
}

t_stack	*ft_add_first(char *argv, t_stack *tail)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (head == NULL)
		return (NULL);
	head -> value = ft_atoi(argv);
	// first -> next = NULL;
    // when only have one node (next && previous pointing to the same?)
    head -> next = NULL; // is this correct?
    head -> previous = NULL;
	return (head);
}

void	ft_print_stack(t_stack *stack, t_stack *head, t_stack *tail) // to be deleted later as we don't need to print out
{
	t_stack	*print_stack;

	print_stack = stack; //equal head?
	printf("the stack a: \n");
	while (print_stack != tail -> next)
	{
		printf("from the first node: %d\n", print_stack -> value);
		print_stack = print_stack -> next;
		printf("am i here?\n");
	}
	printf("the traversed order of stack a: ");
	print_stack = tail;
	// while (print_stack != head)
	// {
	// 	printf("from the last node: %d\n", print_stack -> value);
	// 	print_stack = print_stack -> previous;
	// }
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
    t_stack *head;
    t_stack *tail;
	int		i;

	if (argc == 1 || argv[2] == NULL) // what if "    2"
		return (1);

	stack_a = NULL;
    head = NULL;
    tail = NULL;
	// TO DO: 1) to check if the arguments is number -> LOOPING
	// the argument can give in a " " -> the argument could be only 2 argc if the second argument is " "
	// check the number of the argument -> if argc is 2 -> check split
	// (split to seperate the arugment)
	// split - space / tab -->
	// if more than 2 -> LOOPING to check if a string of array is contain alpha
	// convert string to atoi
	i = 1;
	while (argv[i])
	{
		if (stack_a == NULL)
        {
			stack_a = ft_add_first(argv[i], tail);
            head = stack_a;
        }
		else
			ft_add_to_stack(argv[i], stack_a, head, tail);
		i++;
	}
	ft_print_stack(stack_a, head, tail);

	//Check the output
	// int	i;

	// i = 1;
	// printf("%d\n", argc);
	// while (argv[i])
	// {
	// 	printf("%s\n", argv[i]);
	// 	i++;
	// }
}
