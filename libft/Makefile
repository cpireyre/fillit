# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 11:36:52 by cpireyre          #+#    #+#              #
#    Updated: 2018/05/01 15:01:25 by hwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

CC			=	gcc	
CFLAGS		=	-Wall -Wextra -Werror -I.
BFLAGS		=	-c -o

AR			:=	ar rc
RL			:= 	ranlib
RM			:=	rm -f

NAME		=	libft.a

IO			=	ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c
STRING		=	ft_strlen.c ft_strnew.c ft_strncpy.c ft_strcpy.c ft_strdup.c \
				ft_striter.c ft_strmap.c ft_strclr.c ft_strdel.c ft_strsub.c \
				ft_strchr.c ft_strncmp.c ft_strrev.c ft_strrchr.c ft_strcmp.c \
 				ft_strnequ.c ft_strequ.c ft_striteri.c ft_strmapi.c ft_strlcat.c \
 				ft_strstr.c ft_strnstr.c ft_strncat.c ft_strcat.c ft_strjoin.c \
 				ft_strtrim.c ft_strsplit.c
CTYPE		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			   	ft_isprint.c ft_islower.c ft_isupper.c ft_isspace.c ft_isblank.c
MATH		=	ft_iswithin.c ft_min.c ft_max.c ft_abs.c ft_magnitude.c ft_sqrt.c
CONVERT		=	ft_tolower.c ft_toupper.c ft_itoa_base.c ft_atoi_base.c \
				ft_atoi.c ft_itoa.c
MEM			=	ft_memcpy.c ft_memdel.c ft_memset.c ft_memalloc.c \
				ft_bzero.c ft_memcmp.c ft_memccpy.c ft_memmove.c ft_memchr.c \
 				ft_swap.c
LIST		=	ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstlast.c \
				ft_lstdepth.c ft_lstappend.c ft_lstmap.c ft_lstdel.c

SRC_PATH	= 	./
SRC_NAME	=	$(IO) $(STRING) $(CTYPE) $(MATH) $(CONVERT) $(MEM) $(LIST)
OBJ_PATH	= 	./obj/
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@$(RL) $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(BFLAGS) $@ $<

clean: 
	@$(RM) $(OBJ) 
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, header
