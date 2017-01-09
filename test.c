#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "libftasm.h"

int		main(void)
{
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('z'));
	printf("%d\n", ft_isalpha('A' - 1));
	printf("%d\n", ft_isalpha('Z' + 1));
	printf("%d\n", ft_isalpha('a' - 1));
	printf("%d\n", ft_isalpha('z' + 1));

	return (0);
}