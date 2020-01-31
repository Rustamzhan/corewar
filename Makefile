# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanton <astanton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 16:12:01 by astanton          #+#    #+#              #
#    Updated: 2020/01/31 18:00:38 by astanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = main.c\
		./args_prep/check_args.c\
		./args_prep/decode_arg_byte.c\
		./args_prep/get_and_check_args.c\
		./args_prep/get_args.c\
		./args_prep/get_offset.c\
		./init/init_battle_field.c\
		./init/init_players.c\
		./init/save_info_about_players.c\
		./init/load_exec_code.c\
		./init/carriage_init.c\
		./init/sort_players.c\
		./operations/add.c\
		./operations/aff.c\
		./operations/and.c\
		./operations/fork.c\
		./operations/ld.c\
		./operations/ldi.c\
		./operations/lfork.c\
		./operations/live.c\
		./operations/lld.c\
		./operations/lldi.c\
		./operations/or.c\
		./operations/st.c\
		./operations/sti.c\
		./operations/sub.c\
		./operations/xor.c\
		./operations/zjmp.c\
		./print/introducing.c\
		./print/messages.c\
		./validation/verification.c\
		./validation/verification_binary_files.c\
		debug.c

OBJ =  main.o\
		./args_prep/check_args.o\
		./args_prep/decode_arg_byte.o\
		./args_prep/get_and_check_args.o\
		./args_prep/get_args.o\
		./args_prep/get_offset.o\
		./init/init_battle_field.o\
		./init/init_players.o\
		./init/save_info_about_players.o\
		./init/load_exec_code.o\
		./init/carriage_init.o\
		./init/sort_players.o\
		./operations/add.o\
		./operations/aff.o\
		./operations/and.o\
		./operations/fork.o\
		./operations/ld.o\
		./operations/ldi.o\
		./operations/lfork.o\
		./operations/live.o\
		./operations/lld.o\
		./operations/lldi.o\
		./operations/or.o\
		./operations/st.o\
		./operations/sti.o\
		./operations/sub.o\
		./operations/xor.o\
		./operations/zjmp.o\
		./print/introducing.o\
		./print/messages.o\
		./validation/verification.o\
		./validation/verification_binary_files.o\
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
