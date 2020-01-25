/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:00:46 by astanton          #+#    #+#             */
/*   Updated: 2020/01/10 18:55:32 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_player	*players;
	t_carriage	*carriages;
//	int			a;

	verification_of_incoming_data(ac, av);
	game = init_game();
	players = init_players(ac, av);
	load_exec_code_in_battle_field(game, players);
	carriages = carriage_init(players);
	// debug(players, NULL, 2);
	// debug(NULL, carriages, 4);
	// debug(&game, NULL, 5);
	// debug(game.field, players, 1);

	// load_champs_exec_code(game, players);
	// if (ac == 1)
	// 	return (0);
	// a = ft_atoi(av[1]);
	// debug(&a, 3);
	// a = -(ft_atoi(av[1]));
	// debug(&a, 3);

	// free(game.field);
	// free(players->code);
	// free(players->comment);
	// free(players->name);
	
	return (0);
}
