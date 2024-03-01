/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:14:22 by jjaroens          #+#    #+#             */
/*   Updated: 2023/10/14 12:40:18 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Description: The strchr() function locates the first occurrence of c
//(converted to a char) in the string pointed to by s.
// The terminating null character is considered to be part of the string;
// therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
// Return: The functions strchr() and strrchr() return a pointer to the
// located character, or NULL if the character does not appear in the string.
// #include <stdio.h>
// #include <string.h>
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c || (!*s && (char)c == 0))
		return ((char *)s);
	else
		return (NULL);
}
// int	main(void)
// {
// 	printf("the strchr function: %s\n", strchr(" dfdf ",' '));
// 	printf("the my function: %s\n", ft_strchr(" dfdf",' '));
// }