#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

#include "libfts.h"

/*
Syscall :
	WRITE
	rax -> 0x2000004
	rdi -> STDOUT
	rsi -> value
	rdx -> size
*/

int		cmpIs(int (*func1)(int), int (*func2)(int), char c)
{
	int ret[2];

	ret[0] = func1(c);
	ret[1] = func2(c);
	return (ret[0] == ret[1] ? 1 : 0);
}

void	isTest(void)
{
	char	ascii[ASCII_NB];
	char	*names[NB_IS_FUNCTION] = {"ft_isalpha", "ft_isdigit", "ft_isalnum", "ft_isascii", "ft_isprint", "ft_toupper", "ft_tolower"};
	int		(*ft_ptr[NB_IS_FUNCTION])(int) = {ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_toupper, ft_tolower};
	int		(*ptr[NB_IS_FUNCTION])(int) = {isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower};
	int		errors[NB_IS_FUNCTION];
	int		i, j;
	int		ret;

	for (i = 0; i < ASCII_NB; i++)
		ascii[i] = i;
	for (j = 0; j < NB_IS_FUNCTION; j++)
	{
		errors[j] = 0;
		for (i = 0; i < ASCII_NB; i++)
		{
			ret = cmpIs(ft_ptr[j], ptr[j], ascii[i]);
			if (!ret)
				errors[j] = 1;
		}
	}
	for (i = 0; i < NB_IS_FUNCTION; i++)
	{
		if (!errors[i])
			printf("%s is valid.\n", names[i]);
		else
			printf("%s is invalid.\n", names[i]);
	}
}

int		main(void)
{
	// isTest();

	ft_putnbr('A');

	return (0);
}