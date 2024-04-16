#include <stdio.h>
#include "include/push_swap.h"
#include "include/libft.h"

int	ft_check_dup(char **argv, int argc)
{
	int		i;
	int		j;

	if (!argv || !argc)
		return (1);
	i = 1;
	while (i < argc)
	{
        printf("this is the first:%s\n", argv[i]);
        j = 1;
		while (j < argc)
		{
			if (argv[i] == argv[j + 1])
				return (1);
            printf("this is the second:%s\n", argv[j]);
            j++;
		}

        i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
    int i;
	char **str;

    if (argc == 1 || (!argv[1][0]))
        return (1);
    else if (argc == 2)
        str = ft_split(&argv[1][0], ' ');
	i = 1;
    while (i < argc)
    {
		if (!ft_isdigit(*(int*)argv[i])) // check if this work
			return (1);
		i++;
    }
    ft_printf("%d\n", ft_check_dup(argv, argc));
}
