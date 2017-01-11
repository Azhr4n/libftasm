#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "libfts.h"

int		main(void)
{
	int		ft_ret[4];
	int		ret[4];

	ft_ret[0] = ft_isalpha('0');
	ft_ret[1] = ft_isalpha('9');
	ft_ret[2] = ft_isalpha(' ');
	ft_ret[3] = ft_isalpha('a');

	ret[0] = isalpha('0');
	ret[1] = isalpha('9');
	ret[2] = isalpha(' ');
	ret[3] = isalpha('a');

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3])
		printf("ft_isalpha is valid.\n");
	else
		printf("ft_isalpha is failed.\n");

	ft_ret[0] = ft_isdigit('0');
	ft_ret[1] = ft_isdigit('9');
	ft_ret[2] = ft_isdigit(' ');
	ft_ret[3] = ft_isdigit('a');

	ret[0] = isdigit('0');
	ret[1] = isdigit('9');
	ret[2] = isdigit(' ');
	ret[3] = isdigit('a');

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3])
		printf("ft_isdigit is valid.\n");
	else
		printf("ft_isdigit is failed.\n");

	ft_ret[0] = ft_isalnum('0');
	ft_ret[1] = ft_isalnum('9');
	ft_ret[2] = ft_isalnum(' ');
	ft_ret[3] = ft_isalnum('a');

	ret[0] = isalnum('0');
	ret[1] = isalnum('9');
	ret[2] = isalnum(' ');
	ret[3] = isalnum('a');

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3])
		printf("ft_isalnum is valid.\n");
	else
		printf("ft_isalnum is failed.\n");

	ft_ret[0] = ft_isascii('0');
	ft_ret[1] = ft_isascii('9');
	ft_ret[2] = ft_isascii(' ');
	ft_ret[3] = ft_isascii('a');

	ret[0] = isascii('0');
	ret[1] = isascii('9');
	ret[2] = isascii(' ');
	ret[3] = isascii('a');

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3])
		printf("ft_isascii is valid.\n");
	else
		printf("ft_isascii is failed.\n");
	return (0);
}