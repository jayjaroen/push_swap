/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:09:26 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/28 20:49:26 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// what this function is going to do
// 1. Alpha or number
// 2. if number return
// 3. if not then, moving to split the word (characters)
// 4. convert the argument from string to int

int	ft_is_valid(int argv)
{
	// to check if the argument is number and space
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

int	main(int argc, char **argv)
{
    int	result;

	result = ft_check_argv(argc,argv);
	if (result == 1)
	{
		printf("Error"); //error function
		return (1);
	}
}


// int	main(void)
// {
// 	char *str = "hell000";

// 	printf("%s", str);
// }
