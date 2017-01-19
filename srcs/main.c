#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <strings.h>

#include "libfts.h"

void	bzeroTest(void)
{
	char	*test;
	char	*test2;
	char	*c[2];
	int		error;
	int		len;
	int		i;

	test = strdup("Bonjourno.");
	test2 = strdup("Bonjourno.");
	len = strlen(test);
	error = 0;

	ft_bzero(test, 5 * sizeof(char));
	bzero(test2, 5 * sizeof(char));

	for (i = 0; i < len; i++)
	{
		c[0] = &test[i];
		c[1] = &test2[i];
		if (strncmp(c[0], c[1], 1))
			error = 1;
	}
	if (!error)
		printf("ft_bzero is valid.\n");
	else
		printf("ft_bzero is invalid.\n");
}

void	catTest(void)
{
	int		fd;

	fd = open("Makefile", O_RDONLY);
	ft_cat(fd);
	close(fd);
}

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

void	putsTest(void)
{
	char	*test[3];
	int		error;
	int		ret[2];
	int		i;

	test[0] = strdup("Bonjour ceci est un test.");
	test[1] = strdup("");
	test[2] = strdup(" 	test 	");

	for (i = 0; i < 3; i++)
	{
		ret[0] = ft_puts(test[i]);
		ret[1] = puts(test[i]);
		if (ret[0] != ret[1])
			error = 1;
	}
	if (!error)
		printf("ft_puts is valid.\n");
	else
		printf("ft_puts is invalid.\n");
}

void	strlenTest(void)
{
	char	*test[3];
	int		error;
	int		ret[2];
	int		i;

	test[0] = strdup("Bonjour ceci est un test.");
	test[1] = strdup("");
	test[2] = strdup(" 	test 	");

	error = 0;
	for (i = 0; i < 3; i++)
	{
		ret[0] = ft_strlen(test[i]);
		ret[1] = strlen(test[i]);
		if (ret[0] != ret[1])
			error = 1;
	}
	if (!error)
		printf("ft_strlen is valid.\n");
	else
		printf("ft_strlen is invalid.\n");
}

void	memsetTest(void)
{
	char	*test[2];

	test[0] = (char *)malloc(sizeof(char) * 10);
	test[1] = (char *)malloc(sizeof(char) * 10);

	bzero(test[0], 10);
	bzero(test[1], 10);

	ft_memset(test[0], 'a', 3);
	memset(test[1], 'a', 3);
	ft_memset(test[0], 'b', 3);
	memset(test[1], 'b', 3);
	ft_memset(test[0], 'c', 3);
	memset(test[1], 'c', 3);

	if (!strcmp(test[0], test[1]))
		printf("ft_memset is valid.\n");
	else
		printf("ft_memset is invalid.\n");

}

void	memcpyTest(void)
{
	char	*test[2];
	int		len;

	test[1] = strdup("Style is a bomb di bomb diggydiggy")
	len = strlen(test[1]);
	test[0] = (char *)malloc(sizeof(char) * (len + 1));

	bzero(test[0], 10);
	bzero(test[1], 10);


	if (!strcmp(test[0], test[1]))
		printf("ft_memcpy is valid.\n");
	else
		printf("ft_memcpy is invalid.\n");
}

int		main(void)
{
	bzeroTest();
	catTest();
	isTest();
	putsTest();
	strlenTest();
	memsetTest();
	memsetCpy();
	return (0);
}