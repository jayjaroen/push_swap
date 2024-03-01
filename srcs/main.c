/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:01:48 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/01 17:40:03 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

#include <stdio.h> // To delete printf later

int	main(int argc, char **argv)
{
	// t_node	*list_a;
	// char	*ptr;
	int		result;
	// int		i;
	
	// list_a = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	result = ft_check_argv(argc, argv);//create function to check error
	if (result == 1)
	{
		printf("Error\n");
		return (1);
	}
	// if (argc == 2)
	// {
	// 	ptr = ft_split(argv[1], ' ');
			
	// }
	// else if (argc > 2)
	// {
		
	// }
	
	// list_a = NULL;
    
	// function to check the argv //
}
