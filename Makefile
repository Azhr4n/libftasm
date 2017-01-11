# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 14:01:01 by pivanovi          #+#    #+#              #
#    Updated: 2017/01/11 14:01:02 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libfts.a
TEST		=	test

C_COMPILER	=	gcc
S_COMPILER	=	nasm

CFLAGS		=	-Wall -Wextra -Werror
SFLAGS		=	-f macho64

SRCS_C		=	$(SRCS_DIR)/main.c
SRCS_S		=	$(SRCS_DIR)/ft_strcat.s			\
				$(SRCS_DIR)/ft_isalpha.s		\
				$(SRCS_DIR)/ft_isdigit.s		\
				$(SRCS_DIR)/ft_isalnum.s		\
				$(SRCS_DIR)/ft_isascii.s		\
				$(SRCS_DIR)/ft_isprint.s		\
				$(SRCS_DIR)/ft_toupper.s		\
				$(SRCS_DIR)/ft_tolower.s

SRCS_DIR	=	srcs
HEADER		=	includes
DIR_OBJ		=	obj

S_OBJ		=	$(subst $(SRCS_DIR), $(DIR_OBJ), $(SRCS_S:.s=.o))
C_OBJ		=	$(subst $(SRCS_DIR), $(DIR_OBJ), $(SRCS_C:.c=.o))

all: $(NAME)

$(NAME): $(DIR_OBJ) $(S_OBJ)
	@ar rc $(NAME) $(S_OBJ)
	@ranlib $(NAME)

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.s
	$(S_COMPILER) -f macho64 $< -o $@

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	$(C_COMPILER) $(CFLAGS) -I $(HEADER) -c $^ -o $@

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)

$(TEST): $(NAME) $(C_OBJ)
	$(C_COMPILER) $(CFLAGS) -I $(HEADER) -L . -lfts $(C_OBJ) -o $@

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)

cleantest:
	@rm -f $(TEST)

re: fclean all