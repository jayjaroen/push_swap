/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:09:26 by jjaroens          #+#    #+#             */
/*   Updated: 2024/03/02 16:30:31 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h> // TO BE DELETE later

// what this function is going to do
// 1. Alpha or number
// 2. if number return
// 3. if not then, moving to split the word (characters)
// 4. Duplicate number is not allow
// 5. split the string arguments into words
// 6. convert the argument from string to int atoi
// 7. add the list to node

// ********Edit the printf function later***************
	// to check if the argument is number and space
int	ft_is_valid(int argv)
{
	/// negative and postive ///
	if ((argv >= '0' && argv <= '9') || (argv == 32))
	{
		printf("the argument is valid\n");
		return (0);
	}
	printf("the argument is not valid\n");
	return (1);
}

int    ft_check_argv(int argc, char **argv)
{
    int	i;
	int	j;
	int	result;

	i = 1;
	j = 0;
	result = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			result = ft_is_valid((int)argv[i][j]);
			if (result == 1)
				return (result);
			j++;
		}
		i++;
	}
	return (result);
}
// testing the function ////
int	main(int argc, char **argv)
{
    int	result;
	char **ptr;
	int	i;

	i = 0;
	result = ft_check_argv(argc,argv);
	if (result == 1)
	{
		printf("Error"); //error function
		return (1);
	}
	if (argc == 2)
	{
		ptr = ft_split(argv[1],' '); //ptr to free later
		while (ptr[i])
		{
			printf("the argument is %s\n", ptr[i]);
			i++;
		}
	} // then split the word
}

// over flow int --> atoi // handle 
// duplicate
// int	main(void)
// {
// 	char *str = "hell000";

// 	printf("%s", str);
// }
