/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_battle_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:08:03 by astanton          #+#    #+#             */
/*   Updated: 2020/02/05 05:27:18 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_game		init_game(void)
{
	t_game	game;

	game.field = (unsigned char *)malloc(sizeof(unsigned char) * (MEM_SIZE));
	if (!game.field)
	{
		write(1, "\x1b[35m", 5);
		write(1, "\nMemory for field is not allocated.\n", 36);
		write(1, "\x1b[0m", 4);
		exit(4);
	}
	ft_bzero(game.field, (MEM_SIZE));
	game.carriages = NULL;
	game.last_check_cycle = 0;
	game.last_survivor = 0;
	game.dump = 0;
	game.visualization = 0;
	game.current_cycle = 0;
	game.number_of_checks = 0;
	game.number_of_live_instructions = 0;
	game.cycles_to_die = CYCLE_TO_DIE;
	return (game);
}
