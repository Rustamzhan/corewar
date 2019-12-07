/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_battle_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:08:03 by astanton          #+#    #+#             */
/*   Updated: 2019/12/07 21:56:43 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_game	init_game()
{
	t_game	game;

	game.field = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	if (!game.field)
	{
		write(1, "\x1b[35m", 6);
		write(1, "\nMemory for field is not allocated.\n", 37);
		write(1, "\x1b[0m", 6);
		exit(4);
	}
	ft_bzero(game.field, MEM_SIZE);
	game.current_cycle = 0;
	game.number_of_checks = MAX_CHECKS;
	game.number_of_live_instructions = 0;
	game.cycles_to_die = CYCLE_TO_DIE;

	//debug(game.field, 1);
	return (game);
}
