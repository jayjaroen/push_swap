/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:09:26 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/28 22:31:02 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// what this function is going to do
// 1. Alpha or number
// 2. if number return
// 3. if not then, moving to split the word (characters)
// 4. Duplicate number is not allow
// 5. split the string arguments into words
// 6. convert the argument from string to int atoi
// 7. add the list to node
// Edit the printf function later
/////////////////////// Function from LIBFT to be deleted later//////////////
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr = 0;
		ptr++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (!(src) || !(dst) || !dstsize)
		return (srcsize);
	i = 0;
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
///////////////////////////SPLIT/////////////////////////////////////////////
static size_t	ft_count_sub(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) != '\0' && *(s + i) == c)
			i++;
		if (*(s + i) != '\0')
			count++;
		while (*(s + i) != '\0' && *(s + i) != c)
			i++;
	}
	return (count);
}

static void	free_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*ft_current(char const *s, char c, size_t *len)
{
	size_t	i;

	i = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s != '\0' && *s != c)
	{
		s++;
		i++;
	}
	*len = i;
	return ((char *)s);
}

static char	**ft_allocate(char **new, char const *s, char c)
{
	size_t	len;
	char	**tmp;

	tmp = new;
	while (*s != '\0')
	{
		len = 0;
		s = ft_current(s, c, &len);
		if (len)
		{
			*new = (char *)malloc((sizeof(char)) * len + 1);
			if (*new == NULL)
			{
				free_array(tmp);
				return (NULL);
			}
			ft_strlcpy(*(new++), s - len, len + 1);
		}
	}
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (s == NULL)
		return (NULL);
	new = (char **)ft_calloc(((ft_count_sub(s, c)) + 1), sizeof(char *));
	if (new == NULL)
		return (NULL);
	return (ft_allocate(new, s, c));
}
/////////////////////////////////////////////////////////////////////////////
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


// int	main(void)
// {
// 	char *str = "hell000";

// 	printf("%s", str);
// }
