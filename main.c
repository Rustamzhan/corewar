/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:00:46 by astanton          #+#    #+#             */
/*   Updated: 2020/01/28 20:33:33 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_player	*players;

	verification_of_incoming_data(ac, av);
	game = init_game();
	players = init_players(ac, av, &game);
	load_exec_code_in_battle_field(game, players);
	game.carriages = carriage_init(players);


	//carriages->operation_code = 5;
	// get_and_check_args(&game, carriages);
	// ft_putnbr(carriages->args[0]);
	// ft_putstr("\n");
	// ft_putnbr(carriages->args[1]);
	// ft_putstr("\n");
	// ft_putnbr(carriages->args[2]);
	// ft_putstr("\n");
	// ft_putnbr(carriages->is_args_valid);
	// ft_putstr("\n");
	// ft_putnbr(carriages->offset);
	// ft_putstr("\n");
	//  debug(players, NULL, 2);
	//  debug(NULL, carriages, 4);
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
