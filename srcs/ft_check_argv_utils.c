/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:09:26 by jjaroens          #+#    #+#             */
/*   Updated: 2024/04/17 12:17:04 by jjaroens         ###   ########.fr       */
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

int	ft_atol(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (ft_isdigit(*str))
		exit (1);
	return (result * sign);
}

// int	ft_check_dup(char **argv, int argc)
// {
// 	int		i;
// 	int		j;

// 	if (!argv || !argc)
// 		return (1);
// 	i = -1;
// 	while (++i < argc)
// 	{
// 		j = i + 1;
// 		while (j < argc - 1)
// 		{
// 			ft_printf("the first is%s, and the second is%s\n",argv[i], argv[j]);
// 			if (argv[i] == argv[j])
// 			{
// 				ft_printf("duplicate number found!");
// 				return (1);
// 			}
// 			j++;
// 		}
// 	}
// 	return (0);
// }

// int	ft_is_valid(char *argv)
// {
// 	/// negative and postive ///
//     char	*str;

// 	str = argv;
// 	while (*str)
// 	{
// 		if ((*str >= '0' && *str <= '9') || ((*str == '-' || *str == '+')
// 				&& (*(str + 1) >= '0' && *(str + 1) <= '0'))) //space in the arguments
// 			str++;
// 		else
// 		{
// 			ft_printf("the argument is not valid\n");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// int	ft_check_argv(int argc, char **argv)
// {
// 	int	i;
// 	int	result;

// 	i = -1;
// 	result = 0;
// 	while (argv[++i])
// 	{
// 		result = ft_is_valid(argv[i]);
// 		if (result == 1)
// 			return (result);
// 	}
// 	result = ft_check_dup(argv, argc);
// 	return (result);
// }


// testing the function ////
// int	main(int argc, char **argv)
// {
//     int	result;
// 	char **ptr;
// 	int	i;

// 	i = 0;
// 	result = ft_check_argv(argc,argv);
// 	if (result == 1)
// 	{
// 		printf("Error"); //error function
// 		return (1);
// 	}
// 	if (argc == 2)
// 	{
// 		ptr = ft_split(argv[1],' '); //ptr to free later
// 		while (ptr[i])
// 		{
// 			printf("the argument is %s\n", ptr[i]);
// 			i++;
// 		}
// 	} // then split the word
// }

// over flow int --> atoi // handle
// duplicate
// int	main(void)
// {
// 	char *str = "hell000";

// 	printf("%s", str);
// }
