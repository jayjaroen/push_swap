/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:01:48 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/16 22:20:15 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

/*The main function - Blue Print:
	1. Receive the arguments
	2. Check if the argument is valid: more than 1 argc. If only one argument,
	exit the program
	3. Check if the arguments are 2 argc, check if the second argument contains
	many arguments inside, for instance, "1 2 3 4"
		3.1 looping to check if the arguments contained only numbers - if not, then exit
		3.2 Separate the words inside the arguments" 1 2 3 4"- after making sure that
		it contains only numbers
		3.3 Is there a repeat number in the stack? --> if there is, then exit (double loop?)
	4. Creating a list of arguments A
	5. Check if stack A is sorted - sorted then doing nothing
	6. Sorting stack A (3 arguments -> tiny sort || more than 3):
		6.1 push to stack B
		6.2 the minimum steps to push A & b  */
//
////////////// Test//////////////////////////////////////////////////////
// int	ft_check_dup(char **argv, int argc)
// {
// 	int		i;
// 	int		j;

// 	if (!argv || !argc)
// 		return (1);
// 	i = 1;
// 	while (i < argc)
// 	{
//         ft_printf("this is the first:%s\n", argv[i]);
//         j = 1;
// 		while (j < argc)
// 		{
// 			if (argv[i] == argv[j + 1])
// 				return (1);
//             ft_printf("this is the second:%s\n", argv[j]);
//             j++;
// 		}

//         i++;
// 	}
// 	return (0);
// }

int main(int argc, char **argv)
{
    // int	i;

    if (argc == 1 || (!argv[1][0]))
        return (1);
    else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (ft_check_argv(argc, argv))
			return (1);
	}
	else //./push_swap "22 3 4" "3" "4"
	{
		if (ft_check_argv(argc, ++argv))
		{
			ft_printf("error!\n");
			return (1);
		}
	}
	while (*argv)
	{
		ft_printf("%s\n", *argv);
		argv++;
	}
	// else if (argc > 3) // ./push_swap "22 3 4" "3" "4"
	// calling push swap in another function
}

// int	main(int argc, char **argv)
// {
// 	t_stack	stack_a;
// 	t_stack	stack_b;
// 	int		i;

// 	ft_bzero(&stack_a, sizeof(t_stack));
// 	ft_bzero(&stack_b, sizeof(t_stack));
// 	stack_a.name = 'A';
// 	stack_b.name = 'B';
// 	i = 1;
// 	while (i < argc)
// 	{
// 		ft_add_list_back(&stack_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	// ft_check_duplicate_num(&list);
// 	ft_printf("-----------the stack_a before sorting-----------\n");
// 	ft_print_output(stack_a.head, "main");
// 	ft_sort_stack(&stack_a, &stack_b);
// 	ft_printf("------ stack a after sorting -------\n");
// 	ft_print_output(stack_a.head, "main");
// 	ft_printf("the number of nodes in stack_A:%d\n", stack_a.n);
// 	ft_printf("--------stack b after sorting--------\n");
// 	ft_print_output(stack_b.head, "main");
// 	ft_printf("the number of nodes in stack_B:%d\n", stack_b.n);
// }

// adding new node -> check duplicate



///////////////////////////////Parking lot /////////////////////////////////////////////////////////
// int	main(int argc, char **argv)
// {
// 	/// to include organize the file ft_count_node and all functions in the main
// 	/// in utility
// 	t_stack	stack_a;
// 	t_stack	stack_b;
// 	int i;

// 	ft_bzero(&stack_a, sizeof(t_stack));
// 	ft_bzero(&stack_b, sizeof(t_stack));
// 	i = 1;
// 	while (i < argc)
// 	{
// 		ft_add_list_back(&stack_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	// check duplicate number
// 	// if duplicate, exit out
// 	// count size
// 	// small sort -> algo (within the stack)
// 	// ft_check_duplicate_num(&list);
// 	// size_arg = ft_count_node(&list);
// 	ft_sort_stack(&stack_a, &stack_b);
// 	// ft_print_output(stack_a.head); // the address of reference
// 	ft_printf("the total number of nodes: %d\n", ft_count_node(stack_a.head)); //already a pointer
// 	ft_printf("the maximum value of nodes: %d\n", stack_a.max->value);
// 	ft_printf("the minimum value of nodes: %d\n", stack_a.min->value);
// 	/// check sort take head && min
// 	// printf("%d\n", ft_is_sorted(stack_a.head));

// 	// ft_print_output(stack_a.head);

// 	ft_printf("------ stack a after sorting -------\n");
// 	ft_print_output(stack_a.head);
// 	ft_printf("--------stack b after sorting--------\n");
// 	ft_print_output(stack_b.head);
// }
// int	main(int argc, char **argv)
// {
// 	// t_node	*list_a;
// 	// char	*ptr;
// 	int		result;
// 	// int		i;

// 	// list_a = NULL;
// 	if (argc < 2 || !argv[1][0])
// 		return (1);
// 	result = ft_check_argv(argc, argv);//create function to check error
// 	if (result == 1)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	// if (argc == 2)
// 	// {
// 	// 	ptr = ft_split(argv[1], ' ');

// 	// }
// 	// else if (argc > 2)
// 	// {

// 	// }

// 	// list_a = NULL;

// 	// function to check the argv //
// }
