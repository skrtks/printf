# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skorteka <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/11 09:32:11 by skorteka      #+#    #+#                  #
#    Updated: 2019/12/11 09:32:12 by skorteka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = c_print.c printf.c main.c
CC = gcc
CFLAGS = -I. -Wall -Werror -Wextra
NAME = printf.a
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJS)
	cd libft && make
	$(CC) $(CFLAGS) -g -L./libft -lft $(SRCS) -o printf

asan: $(OBJS)
	cd libft && make
	$(CC) $(CFLAGS) -fsanitize=address -O1 -fno-omit-frame-pointer \
	-g -L./libft -lft $(SRCS) -o printf

.PHONY: clean fclean re all test

clean:
	cd libft && make clean
	-rm -f $(OBJS)

fclean: clean
	cd libft && make fclean
	-rm -f $(NAME)
	-rm -f printf
	-rm -rf printf.dSYM/

re: fclean all
