/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_battle_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:08:03 by astanton          #+#    #+#             */
/*   Updated: 2020/01/26 23:07:20 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_op	g_ops[16] =
{
	{1, {T_DIR, 0, 0}, 10, 0, 4, 0},
	{2, {T_DIR | T_IND, T_REG, 0}, 5, 1, 4, 1},
	{2, {T_REG, T_REG | T_IND, 0}, 5, 0, 4, 1},
	{3, {T_REG, T_REG, T_REG}, 10, 1, 4, 1},
	{3, {T_REG, T_REG, T_REG}, 10, 1, 4, 1},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 1, 4, 1},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 1, 4, 1},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 1, 4, 1},
	{1, {T_DIR, 0, 0}, 20, 0, 2, 0},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 25, 0, 2, 1},
	{3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR}, 25, 0, 2, 1},
	{1, {T_DIR, 0, 0}, 800, 0, 2, 0},
	{2, {T_DIR | T_IND, T_REG, 0}, 10, 1, 4, 1},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 50, 1, 2, 1},
	{1, {T_DIR, 0, 0}, 1000, 0, 2, 0},
	{1, {T_REG, 0, 0}, 2, 0, 4, 1}
};

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
	game.last_survivor = 0;
	game.current_cycle = 0;
	game.number_of_checks = 0;
	game.number_of_live_instructions = 0;
	game.cycles_to_die = CYCLE_TO_DIE;
	return (game);
}
