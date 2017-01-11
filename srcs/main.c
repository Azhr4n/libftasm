#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "libfts.h"

int		main(void)
{
	printf("%d\n", ft_isascii('0'));
	printf("%d\n", ft_isascii('9'));
	printf("%d\n", ft_isascii(' '));
	printf("%d\n", ft_isascii('a'));

	printf("%d\n", isascii('0'));
	printf("%d\n", isascii('9'));
	printf("%d\n", isascii(' '));
	printf("%d\n", isascii('a'));
	return (0);
}