# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolff <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 14:20:18 by hwolff            #+#    #+#              #
#    Updated: 2018/05/01 15:04:20 by hwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make re clean fclean

.SUFFIXES:

NAME = fillit 

LIB_PATH	= libft
LIB			= $(LIB_PATH)/libft.a
LIBK_LINK	= -L $(LIB_PATH)

SRCS = minxmax.c read.c tools.c tetro.c list.c fillit.c grid.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./libft/

all: $(NAME)

$(LIB):
	make -C $(LIB_PATH)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $^

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(LIB) -o $@ $(OBJS)

clean:
	@rm -rf $(OBJS) ./libft/obj/ 

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all
