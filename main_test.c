#include "libft.h"

int main(void)
{
	ft_putstr_fd("hello\n", 1);
	char *str = "lskjdflksjf lskdjflj lsdfkj ljsfdkj sdalfj lskaj lkasdfj";
	char **strs = ft_split(str, 32);
	for (int i = 0; strs[i]; i++) ft_putendl_fd(strs[i], 1);

	return (0);
}