/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:57:07 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/17 16:49:49 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (int argc, char** argv)
{
	
	int i, j;
    int count[10] = {0}; // Assuming ASCII characters 

	printf("%i\n", argc);
    for (i = 1; i < argc; i++)
    {
        char* arg = argv[i]; // number && characters ??
        while (*arg != '\0')
        {
            j = (unsigned char)(*arg);
            ++count[j];
            ++arg;
        }
    }

    for (j = 0; j < argc - 1; j++)
    {
        printf("Character '%d' appears %d times\n", j, count[j]);
    }
	j = 1;
	while (count[j] > 0)
	{
		count[j] = count[j] + count[j - 1];
	}
	j = 0;
	printf("organize the order of the numbers: ");
	while (count[j] != 0)
		printf("%i\n", count[j]);
    return 0;
	// reorganizing the index of count
	// int	i;
	// int j;
	// int count[10];
	// char *arg;

	// for (i = 0; i < argc; i++)
	// {
	// 	arg = argv[i];
	// 	j = (unsigned char)(*arg);
	// 	count[j]++;
	// }
	// j = 0;
	// while (count[j])
	// {
	// 	printf("the character: %c\n, appear %d\n times", j, count[j]);
	// 	j++;
	// }
	
	// printf("%i\n", argc);
	// while (i < argc)
	// {
	// 	printf("%s\n", argv[i]);
	// 	i++;
	// }
}