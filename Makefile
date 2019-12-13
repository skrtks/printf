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

SRCS = c_print.c printf.c
CC = gcc
CFLAGS = -I. -Wall -Werror -Wextra
NAME = libftprintf.a
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make
	cp ./libft/libft.a .
	mv libft.a $(NAME)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJS) $(NAME)
	$(CC) $(CFLAGS) -g -L. -lftprintf $(SRCS) main.c -o printf

asan: $(OBJS) $(NAME)
	$(CC) $(CFLAGS) -fsanitize=address -O1 -fno-omit-frame-pointer \
	-g -L. -lftprintf $(SRCS) main.c -o printf

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
