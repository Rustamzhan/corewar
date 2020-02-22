.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror -g

ASM = ../asm
SRC_ASM_NAME =  asm_content.c \
				assemble.c \
				disassemble.c \
				parse_chmp_exec_code.c \
				write_args.c \
				parse_name_comt_cs.c \
				buffer.c \
				error.c \
				file.c \
				fill_file.c \
				fill_write_arg.c \
				fill_write_code_arg.c \
				fill_write_code_instraction.c \
				in_bytecode.c \
				interpretation.c \
				main.c \
				string.c \
				title.c \
				tokenizing.c \
				validation.c \
				clean_memory.c \
				rebase_str.c \
				label_validation.c \
				do.c

OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o);
SRC_ASM = $(addprefix $(OBJDIR)/, $(SRC_ASM_NAME))
OBJ_ASM = $(addprefix $(OBJDIR)/, $(OBJ_ASM_NAME))

all: libft $(ASM)

$(ASM): $(OBJ_ASM)
	gcc $(FLAGS) $^ -o $@ $(HEADER_LIBFT) $(HEADER) -L libft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/asm.h include/dasm.h
	@mkdir -p $(OBJDIR)
	gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<

libft:
	make -C $(LIBDIR)

clean:
	make clean -C $(LIBDIR)
	rm -Rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -Rf $(ASM)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include