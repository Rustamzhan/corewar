/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:35:00 by astanton          #+#    #+#             */
/*   Updated: 2019/12/03 21:30:21 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"

# define HEX_STRING 	"0123456789abcdef"
# define BYTE_1			0xff
# define BYTE_2			0xff00
# define BYTE_3			0xff0000
# define BYTE_4			0xff000000
# define LINE_LENGTH	32
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
}				t_player;

typedef struct	s_game
{
	t_player	*last_survivor;
	int			current_cycle;
	int			number_of_live_instructions;
	int			cycles_to_die;
	int			number_of_checks;
	char		*field;
}				t_game;

void			verification_of_incoming_data(int ac, char **av);
void			ft_print_usage_and_exit();
void			check_binary_files(int *types, char **av, int ac, int files);
void			ft_print_message_wrong_exec_size(char *file);
void			ft_print_message_wrong_null_marker(char *file);

#endif
