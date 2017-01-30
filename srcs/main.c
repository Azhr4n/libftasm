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
	error = 0;
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
	char	cpy[] = "Bonjour ceci est un test";

	test[0] = strdup("Style is a bomb di bomb diggydiggy");
	test[1] = strdup("Style is a bomb di bomb diggydiggy");

	ft_memcpy(test[0], cpy, 10);
	memcpy(test[1], cpy, 10);

	ft_memcpy(test[0] + 10, cpy + 8, 10);
	memcpy(test[1] + 10, cpy + 8, 10);

	if (!strcmp(test[0], test[1]))
		printf("ft_memcpy is valid.\n");
	else
		printf("ft_memcpy is invalid.\n");
}

void	strdupTest(void)
{
	char	*test[2];

	test[0] = ft_strdup("Ceci est un abordage moussaillon.");
	test[1] = strdup("Ceci est un abordage moussaillon.");
	if (!strcmp(test[0], test[1]))
		printf("ft_strdup is valid.\n");
	else
		printf("ft_strdup is invalid.\n");
}

void	strcmpTest(void)
{
	char	*test[2];
	int		ret[2];
	int		error = 0;

	test[0] = "Bonjour on test.";
	test[1] = "Bonjour on test.";

	ret[0] = ft_strcmp(test[0], test[1]);
	ret[1] = strcmp(test[0], test[1]);
	if (ret[0] != ret[1])
		error = 1;

	test[0] = "Bonjour ca fail.";
	test[1] = "Bonjour on test.";
	ret[0] = ft_strcmp(test[0], test[1]);
	ret[1] = strcmp(test[0], test[1]);
	if (ret[0] != ret[1])
		error = 1;

	if (error)
		printf("ft_strcmp is invalid\n");
	else
		printf("ft_strcmp is valid.\n");

	test[0] = "Bonjour on test.";
	test[1] = "Bonjour on test.";

	ret[0] = ft_strncmp(test[0], test[1], 7);
	ret[1] = strncmp(test[0], test[1], 7);
	if (ret[0] != ret[1])
		error = 1;
	ret[0] = ft_strncmp(test[0], test[1], 25);
	ret[1] = strncmp(test[0], test[1], 25);
	if (ret[0] != ret[1])
		error = 1;

	test[0] = "Bonjour ca fail.";
	test[1] = "Bonjour on test.";
	ret[0] = ft_strncmp(test[0], test[1], 7);
	ret[1] = strncmp(test[0], test[1], 7);
	if (ret[0] != ret[1])
		error = 1;
	ret[0] = ft_strncmp(test[0], test[1], 25);
	ret[1] = strncmp(test[0], test[1], 25);
	if (ret[0] != ret[1])
		error = 1;

	if (error)
		printf("ft_strncmp is invalid\n");
	else
		printf("ft_strncmp is valid.\n");
}

void	strstrTest(void)
{
	char	*test[2];
	char	*ret[2];
	int		error = 0;

	test[0] = "Bonjour on cherche ici.";
	test[1] = "n cher";

	ret[0] = ft_strstr(test[0], test[1]);
	ret[1] = strstr(test[0], test[1]);
	if (ret[0] != ret[1])
		error = 1;

	test[1] = "Bob";
	ret[0] = ft_strstr(test[0], test[1]);
	ret[1] = strstr(test[0], test[1]);
	if (ret[0] != ret[1])
		error = 1;

	test[1] = "";
	ret[0] = ft_strstr(test[0], test[1]);
	ret[1] = strstr(test[0], test[1]);
	if (ret[0] != ret[1])
		error = 1;

	if (!error)
		printf("ft_strstr is valid.\n");
	else
		printf("ft_strstr is not valid\n");
}

void	strcpyTest(void)
{
	char	*str;
	char	*ret[2];

	ret[0] = (char *)malloc(sizeof(char) * 30);
	ret[1] = (char *)malloc(sizeof(char) * 30);

	str = "Ca copie, ca copie";
	ret[0] = ft_strcpy(ret[0], str);
	ret[1] = ft_strcpy(ret[1], str);

	if (strcmp(ret[0], ret[1]))
		printf("ft_strcpy is invalid.\n");
	else
		printf("ft_strcpy is valid.\n");
}

void	putnbrTest(void)
{
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-1);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(2147483647);
	printf("\n");
}

int		main(void)
{
	bzeroTest();
	catTest();
	isTest();
	putsTest();
	strlenTest();
	memsetTest();
	memcpyTest();
	strdupTest();
	//Bonus
	strcmpTest();
	strstrTest();
	strcpyTest();
	putnbrTest();
	return (0);
}