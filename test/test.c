
#include <stdio.h>

char	*test(char *str);

int	main(void)
{
	char *ret = test("ab");

	printf("%s\n", ret);

	return (0);
}