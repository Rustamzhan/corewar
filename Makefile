# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanton <astanton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 16:12:01 by astanton          #+#    #+#              #
#    Updated: 2019/12/03 19:29:02 by astanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = main.c\
		verification.c\
		verification_binary_files.c\
		messages.c

OBJ =  main.o\
		verification.o\
		verification_binary_files.o\
		messages.o

HDR = ./libft/includes/

FLAG = -Wall -Wextra -Werror

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(OBJ) ./libft/libft.a
	gcc -o $(NAME) $(OBJ) -L ./libft -lft

$(OBJ): %.o: %.c
	gcc -g $(FLAG) -c -I $(HDR) -I ./srcs $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
