/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:35:00 by astanton          #+#    #+#             */
/*   Updated: 2020/02/04 15:43:00 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"

# define BYTE_1			0xff
# define BYTE_2			0xff00
# define BYTE_3			0xff0000
# define BYTE_4			0xff000000
# define LINE_LENGTH	64
# define TYPE_OPT_N		1
# define TYPE_OPT_DUMP	2
# define TYPE_FILE		3
# define TYPE_NUMBER	4

typedef struct	s_player
{
	char			*name;
	char			*comment;
	unsigned char	*code;
	int				player_id;
	int				size_of_code;
	struct s_player	*next;
	struct s_player	*prev;
}				t_player;

typedef struct	s_carriage
{
	int					id;
	int					cycles_till_exec;
	int					position;
	int					cur_position;
	int					carry;
	int					operation_code;
	int					last_live_cycle;
	int					offset;
	int					is_args_valid;
	int					args_type[3];
	int					args[3];
	int					reg[REG_NUMBER];
	struct s_carriage	*next;
}				t_carriage;

typedef struct	s_game
{
	int					dump;
	int					dump_cycles;
	int					visualization;
	int					last_survivor;
	int					current_cycle;
	int					last_check_cycle;
	int					number_of_live_instructions;
	int					cycles_to_die;
	int					number_of_checks;
	char				players_id;
	struct s_carriage	*carriages;
	struct s_player		*players;
	unsigned char		*field;
}				t_game;

typedef struct	s_op
{
	char	*name;
	int		num_of_args;
	int		arg_types[4];
	int		cycles_to_exec;
	int		change_carry;
	int		dir_size;
	int		args_byte;
	int		idx_mod;
}				t_op;

static t_op	g_ops[16] =
{
	{"live", 1, {T_DIR, 0, 0, 0}, 10, 0, 4, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0, 0}, 5, 1, 4, 1, 1},
	{"st", 2, {T_REG, T_REG | T_IND, 0, 0}, 5, 0, 4, 1, 1},
	{"add", 3, {T_REG, T_REG, T_REG, 0}, 10, 1, 4, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG, 0}, 10, 1, 4, 1, 1},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG, 0},
		6, 1, 4, 1, 1},
	{"or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG, 0},
		6, 1, 4, 1, 1},
	{"xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG, 0},
		6, 1, 4, 1, 1},
	{"zjmp", 1, {T_DIR, 0, 0, 0}, 20, 0, 2, 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG, 0},
		25, 0, 2, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR, 0},
		25, 0, 2, 1, 1},
	{"fork", 1, {T_DIR, 0, 0, 0}, 800, 0, 2, 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0, 0}, 10, 1, 4, 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG, 0},
		50, 1, 2, 1, 0},
	{"lfork", 1, {T_DIR, 0, 0, 0}, 1000, 0, 2, 0, 0},
	{"aff", 1, {T_REG, 0, 0, 0}, 2, 0, 4, 1, 0}
};

char			*save_name(int fd);
char			*save_comment(int fd);
unsigned char	*save_exec_code(int fd, int size_of_code);
t_game			init_game();
t_player		*init_players(int ac, char **av, t_game *game);
t_player		*sort_players(t_player *players);
t_carriage		*carriage_init(t_player *players);
int				*decode_arg_byte(unsigned char byte, int op_code);
int				get_offset(int *args, int op_code);
int				check_args(int *args, int op_code);
int				save_size_of_code(int fd);
void			get_args(int *args_type, t_game *game, t_carriage *carriage);
void			get_and_check_args(t_game *game, t_carriage *carriage);
void			add(t_game *game, t_carriage *carriage);
void			aff(t_game *game, t_carriage *carriage);
void			and(t_game *game, t_carriage *carriage);
void			ft_fork(t_game *game, t_carriage *carriage);
void			ld(t_game *game, t_carriage *carriage);
void			ldi(t_game *game, t_carriage *carriage);
void			lfork(t_game *game, t_carriage *carriage);
void			live(t_game *game, t_carriage *carriage);
void			lld(t_game *game, t_carriage *carriage);
void			lldi(t_game *game, t_carriage *carriage);
void			or(t_game *game, t_carriage *carriage);
void			st(t_game *game, t_carriage *carriage);
void			sti(t_game *game, t_carriage *carriage);
void			sub(t_game *game, t_carriage *carriage);
void			xor(t_game *game, t_carriage *carriage);
void			zjmp(t_game *game, t_carriage *carriage);
void			debug(void *arg, void *arg2, int var);
void			verification_of_incoming_data(int ac, char **av, t_game *game);
void			ft_print_usage_and_exit();
void			check_binary_files(int *types, char **av, int ac, int files);
void			ft_print_message_wrong_exec_size(char *file);
void			ft_print_message_wrong_null_marker(char *file);
void			load_exec_code_in_battle_field(t_game game, t_player *players);
void			introducing_players(t_player *players);
void			start_game(t_game *game);
void			exec_all_carriages(t_game *game);
void			check_carriages(t_game *game);
void			dump_field(unsigned char *field);
void			print_winner(t_game *game);
void			free_resources(t_game game);

#endif
