/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:29:06 by astanton          #+#    #+#             */
/*   Updated: 2020/01/26 22:10:01 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ld(t_game *game, t_carriage *carriage)
{
	int *args_type;

	args_type = decode_arg_byte(game->field[(carriage->position + 1) % MEM_SIZE], carriage->operation_code - 1);
	carriage->offset = get_offset(args_type, carriage->operation_code - 1);
	if (check_args(args_type, carriage->operation_code - 1))
	{
		carriage->is_args_valid = 0;
		return ;
	}
	get_args(args_type, game, carriage);
}
