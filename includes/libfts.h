/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:23:39 by pivanovi          #+#    #+#             */
/*   Updated: 2017/01/09 12:23:41 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

# define ASCII_NB 127
# define NB_IS_FUNCTION 7

void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *dest, const char *src);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

size_t		ft_strlen(const char *s);
int			ft_puts(const char *s);

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);

char		*ft_strdup(const char *s);
void		ft_cat(int fd);

/*Bonus*/
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strcpy(char *dst, const char *src);
int			ft_putnbr(int n);

#endif
