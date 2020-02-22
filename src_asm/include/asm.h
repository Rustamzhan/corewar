/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 22:30:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define PATTERN_T_REG "^r[0-9]{1,2}$"
# define PATTERN_T_DIR "^%-?0*[0-9]+$|^%:[0-9a-z_]+$"
# define PATTERN_T_IND "^-?[0-9]+$|^:[0-9a-z_]+$"
# define INSTRACTION 0
# define LABEL "^[0-9a-z_]+:$"
# define REGISTER "^r[0-9]{1,2}$"
# define DIRECT_LABEL "^%:[0-9a-z_]+$"
# define DIRECT "^%-?0*[0-9]+$"
# define INDIRECT_LABEL "^:[0-9a-z_]+$"
# define INDIRECT "^-?[0-9]+$"
# define PATTERN_NAME_CHAMPS "^[ 	]*[.]name[ 	]*\".*\"[ 	]*([#;].*)?$"
# define PATTERN_COMMENT_CHAMPS 1
# define PATTERN_COMMENT "^ *[#;].*$"
# define PATTERN_SPACE_OR_EMPTY_LINE "^[ 	]*$"
# define PATTERN 2
# define PATTERN_NAME_OR_COMMENT_CHAMPS_FIRST_STAGE 3
# define PATTERN_HELP_VALIDATION_FIRST_CASE 4
# define PATTERN_HELP_VALIDATION_SECOND_CASE 5
# define PATTERN_HELP_VALIDATION_THIRD_CASE 6
# define PATTERN_HELP_VALIDATION_FOURTH_CASE 7
# define PATTERN_HELP_VALIDATION_FIFTH_CASE "^[0-9a-z_]+:[#;].*$"

# include "libft.h"
# include "op.h"
# include "dasm.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <regex.h>
# include <stdint.h>
# include <inttypes.h>

# define ASSEMBLE 'c'
# define DISASSEMBLE 's'
# define EXP_ASM ".s"
# define EXP_COR ".cor"
# define EXP_ASM_LEN 2
# define EXP_COR_LEN 4
# define BUFF_S 2048
# define OCTET_SIZE 8
# define HEADER_SIZE 2192
# define FOURTH_BYTE 3

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x10

# define LIVE_NAME "live"
# define LD_NAME "ld"
# define ST_NAME "st"
# define ADD_NAME "add"
# define SUB_NAME "sub"
# define AND_NAME "and"
# define OR_NAME "or"
# define XOR_NAME "xor"
# define ZJMP_NAME "zjmp"
# define LDI_NAME "ldi"
# define STI_NAME "sti"
# define FORK_NAME "fork"
# define LLD_NAME "lld"
# define LLDI_NAME "lldi"
# define LFORK_NAME "lfork"
# define AFF_NAME "aff"

# define ONE_BYTE 1
# define TWO_BYTE 2
# define FOUR_BYTE 4

# define UNCERTAIN_NAME "UNCERTAIN"
# define LABEL_NAME "LABEL"
# define INSTRACTION_NAME "INSTRACTION"
# define REGISTER_NAME "REGISTER"
# define DIRECT_LABEL_NAME "DIRECT_LABEL"
# define DIRECT_NAME "DIRECT"
# define INDIRECT_LABEL_NAME "INDIRECT_LABEL"
# define INDIRECT_NAME "INDIRECT"

typedef	struct			s_token
{
	int					memory_size;
	char				*content;
	char				*type;
	struct s_token		*next;
	struct s_token		*previous;
}						t_token;

typedef struct			s_strings
{
	t_token				*string;
	struct s_strings	*next;
}						t_strings;

typedef struct			s_asm_content
{
	int					fd_dst;
	int					fd_src;
	char				asm_dsm_flag;
	int					flag_name;
	int					flag_comment;
	int					flag_pattern;
	int					memory_code_size;
	char				*reg[8];
	char				*line;
	char				*buf;
	char				*new_filename;
	int					b_pos;
	t_strings			**tokens;
	char				*name;
	char				*comment;
	t_header			*header;
	char				*bytecode;
	unsigned int		exec_code_size;
	unsigned int		asm_size;
	unsigned int		header_size;
}						t_asm_content;

t_asm_content			*init_content(char ad_flag);
void					assemble(t_asm_content **content);
char					*clean_memory_t_strings(t_strings *rows);
void					disassemble(t_asm_content **content);
void					parse_chmp_exec_code(t_asm_content **content);
u_int8_t				get_num_from_1byte(t_asm_content **content, int *i);
int						get_num_from_nbyte(t_asm_content **content, int *i,
u_int8_t t_dir_size);
void					get_args_types(t_asm_content **content, int *i,
u_int8_t cur_op);
void					write_curr_op(t_asm_content **content, int *i,
u_int8_t cur_op);
void					write_reg(t_asm_content **content,
u_int8_t cur_op, int *i, int j);
void					write_dir(t_asm_content **content,
u_int8_t cur_op, int *i, int j);
void					write_ind(t_asm_content **content,
u_int8_t cur_op, int *i, int j);
int						file_is_binary(int fd, t_asm_content **content);
int						parse_name(char *buff, int *b_pos, int fd,
t_asm_content **content);
int						parse_comment(char *buff, int *b_pos, int fd,
t_asm_content **content);
void					skip_null_bytes(t_asm_content **content);
void					parse_chmp_exec_code_size(t_asm_content **content);
void					clear_buff(char **buff);
char					**create_buff(char **line, t_asm_content **content);
void					error(t_asm_content *content);
void					print_output_str(t_asm_content **content);
int						file(const char *filename, t_asm_content **content);
void					what_are_strings(t_strings *rows);
int						skip_simple_comment_emptyline(char **line);
int						check_name_or_comment(char **buff,
t_asm_content **content);
void					tokenizing(char **line, t_strings **row,
t_asm_content **content);
void					add_string(t_token **tokens,
t_strings **row, t_asm_content *content);
void					in_bytecode(t_asm_content **content);
void					interpretation(t_token *tokens, t_asm_content *cozel);
int						parse(char *str, char *pattern);
char					*help_check_name_or_comment_champs(t_asm_content
*content, int fd);
char					*check_valid(t_asm_content *content, int fd);
char					*search_label(t_strings *rows, char *content);
char					*check_all_label(t_strings *rows, t_asm_content
**struct_content);
int						check(t_token *pointer);
void					fill_write(t_token *pointer, t_strings *rows,
t_asm_content **content);
void					fill_file(t_strings *rows, t_asm_content
**content);
int						search_instraction_two(t_token *pointer);
int						search_instraction(char *content,
t_strings *rows);
void					write_args(int length, int num,
t_asm_content **content);
int						check_t_dir_size(t_token *pointer);
void					fill_write_arg(t_token *pointer,
t_strings *rows, t_asm_content **content, int flag);
void					fill_write_code_arg(t_token *pointer,
t_asm_content **content);
void					fill_write_code_instraction(char *instraction,
t_asm_content **content);
char					*clean_memory(t_asm_content **content);
char					*rebase_str_first_case(char *content);
char					*rebase_str_second_case(char *content);
char					*rebase_str_third_case(char *content);
char					*rebase_str_fourth_case(char *content);
char					*rebase_str_fifth_case(char *content);
char					*label_validation(t_token *pointer, char *content);
int						check_all_label_size(t_token *pointer,
t_asm_content			**struct_content, int flag);
char					fill_write_code_instraction_help(char *instraction,
char c);
char					*do_w1(t_asm_content *content, char *temp);
char					*do_w2(t_asm_content *content, char *temp);

#endif
