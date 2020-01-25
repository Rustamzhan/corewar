# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanton <astanton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 16:12:01 by astanton          #+#    #+#              #
#    Updated: 2020/01/10 17:48:43 by astanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = main.c\
		./validation/verification.c\
		./validation/verification_binary_files.c\
		./init/init_battle_field.c\
		./init/init_players.c\
		./init/save_info_about_players.c\
		./init/load_exec_code.c\
		./init/carriage_init.c\
		./operations/live.c\
		messages.c\
		debug.c

OBJ =  main.o\
		./validation/verification.o\
		./validation/verification_binary_files.o\
		./init/init_battle_field.o\
		./init/init_players.o\
		./init/save_info_about_players.o\
		./init/load_exec_code.o\
		./init/carriage_init.o\
		./operations/live.o\
		messages.o\
		debug.o

HDR = ./libft/includes/
HDR1 = ./includes

FLAG = -Wall -Wextra -Werror

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(OBJ) ./libft/libft.a
	gcc -o $(NAME) $(OBJ) -L ./libft -lft

$(OBJ): %.o: %.c ./includes/vm.h ./includes/op.h
	gcc -g $(FLAG) -c -I $(HDR) -I $(HDR1) $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
