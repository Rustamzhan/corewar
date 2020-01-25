/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:35:00 by astanton          #+#    #+#             */
/*   Updated: 2020/01/10 20:50:11 by astanton         ###   ########.fr       */
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
	unsigned int		id;
	unsigned int		carry;
	unsigned int		operation_code;
	unsigned int		last_live_cycle;
	unsigned int		cycles_till_exec;
	unsigned int		step;
	unsigned int		position;
	int					reg[REG_NUMBER];
	struct s_carriage	*next;

}				t_carriage;


typedef struct	s_game
{
	int				flags;
	int				dump;
	int				last_survivor;
	int				current_cycle;
	int				number_of_live_instructions;
	int				cycles_to_die;
	int				number_of_checks;
	unsigned char	*field;
}				t_game;

typedef struct	s_op
{
	int	num_of_attr;
	int attr_types[3];
	int	cycles_to_exec;
	int carry_change;
}				t_op;

void			debug(void *arg, void *arg2, int var);
void			verification_of_incoming_data(int ac, char **av);
void			ft_print_usage_and_exit();
void			check_binary_files(int *types, char **av, int ac, int files);
void			ft_print_message_wrong_exec_size(char *file);
void			ft_print_message_wrong_null_marker(char *file);
void			load_exec_code_in_battle_field(t_game game, t_player *players);
char			*save_name(int fd);
char			*save_comment(int fd);
int				save_size_of_code(int fd);
unsigned char	*save_exec_code(int fd, int size_of_code);
t_game			init_game();
t_player		*init_players(int ac, char **av);
t_carriage		*carriage_init(t_player *players);
void			live(t_game *game, t_carriage *carriage);

#endif
