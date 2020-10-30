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

SRCS = srcs/utils_1.c srcs/utils_2.c srcs/utils_3.c srcs/ft_itoa_base.c\
		srcs/p_print.c srcs/x_print.c srcs/c_print.c srcs/u_print.c srcs/s_print.c srcs/i_print.c srcs/printf.c
CC = gcc
CFLAGS = -Iincludes -Wall -Werror -Wextra
NAME = libftprintf.a
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make
	cp ./libft/libft.a ./$(NAME)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

test: $(OBJS) $(NAME)
	$(CC) -I. -g -L. -lftprintf $(SRCS) main.c -o printf

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
