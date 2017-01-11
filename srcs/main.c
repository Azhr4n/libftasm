#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "libfts.h"

int		main(void)
{
	int		ft_ret[5];
	int		ret[5];

	ft_ret[0] = ft_isalpha('0');
	ft_ret[1] = ft_isalpha('9');
	ft_ret[2] = ft_isalpha(15);
	ft_ret[3] = ft_isalpha('a');
	ft_ret[4] = ft_isalpha(260);

	ret[0] = isalpha('0');
	ret[1] = isalpha('9');
	ret[2] = isalpha(15);
	ret[3] = isalpha('a');
	ret[4] = isalpha(260);

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3]
		&& ret[4] == ft_ret[4])
		printf("ft_isalpha is valid.\n");
	else
		printf("ft_isalpha is failed.\n");

	ft_ret[0] = ft_isdigit('0');
	ft_ret[1] = ft_isdigit('9');
	ft_ret[2] = ft_isdigit(15);
	ft_ret[3] = ft_isdigit('a');
	ft_ret[4] = ft_isdigit(260);

	ret[0] = isdigit('0');
	ret[1] = isdigit('9');
	ret[2] = isdigit(15);
	ret[3] = isdigit('a');
	ret[4] = isdigit(260);

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3]
		&& ret[4] == ft_ret[4])
		printf("ft_isdigit is valid.\n");
	else
		printf("ft_isdigit is failed.\n");

	ft_ret[0] = ft_isalnum('0');
	ft_ret[1] = ft_isalnum('9');
	ft_ret[2] = ft_isalnum(15);
	ft_ret[3] = ft_isalnum('a');
	ft_ret[4] = ft_isalnum(260);

	ret[0] = isalnum('0');
	ret[1] = isalnum('9');
	ret[2] = isalnum(15);
	ret[3] = isalnum('a');
	ret[4] = isalnum(260);

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3]
		&& ret[4] == ft_ret[4])
		printf("ft_isalnum is valid.\n");
	else
		printf("ft_isalnum is failed.\n");

	ft_ret[0] = ft_isascii('0');
	ft_ret[1] = ft_isascii('9');
	ft_ret[2] = ft_isascii(15);
	ft_ret[3] = ft_isascii('a');
	ft_ret[4] = ft_isascii(260);

	ret[0] = isascii('0');
	ret[1] = isascii('9');
	ret[2] = isascii(15);
	ret[3] = isascii('a');
	ret[4] = isascii(260);

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3]
		&& ret[4] == ft_ret[4])
		printf("ft_isascii is valid.\n");
	else
		printf("ft_isascii is failed.\n");

	ft_ret[0] = ft_isprint('0');
	ft_ret[1] = ft_isprint('9');
	ft_ret[2] = ft_isprint(15);
	ft_ret[3] = ft_isprint('a');
	ft_ret[4] = ft_isprint(260);

	ret[0] = isprint('0');
	ret[1] = isprint('9');
	ret[2] = isprint(15);
	ret[3] = isprint('a');
	ret[4] = isprint(260);

	if (ret[0] == ft_ret[0]
		&& ret[1] == ft_ret[1]
		&& ret[2] == ft_ret[2]
		&& ret[3] == ft_ret[3]
		&& ret[4] == ft_ret[4])
		printf("ft_isprint is valid.\n");
	else
		printf("ft_isprint is failed.\n");
	return (0);
}