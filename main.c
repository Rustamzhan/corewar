/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:00:46 by astanton          #+#    #+#             */
/*   Updated: 2019/12/08 00:34:37 by astanton         ###   ########.fr       */
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
	players = init_players(ac, av);
	debug(players, 2);

	free(game.field);
	free(players->code);
	free(players->comment);
	free(players->name);
	//init_palyers(ac, av);
	
	// buff = malloc(1000);
	// nbr = 0;
	// n = 0;
	// ret = read(fd, buff, 4);
	// {
	// 	i = 0;
	// 	buff[ret] = '\0';
	// 	while (i < 4)
	// 	{
	// 		j = 8;
	// 		while (--j >= 0)
	// 			ft_putnbr((buff[i] >> j) & 1);
	// 		write(1, "\n", 1);
	// 		write(1, &(HEX_STRING[((buff[i]) >> 4) & 15]), 1);
	// 		write(1, &(HEX_STRING[(buff[i]) & 15]), 1);
	// 		write(1, "\n", 1);
	// 		i++;
	// 		// j = i * 8;
	// 		// while (--j >= 0)
	// 		// 	ft_putnbr((nbr >> j) & 1);
	// 		// write(1, "\n", 1);
	// 		// if (i != 2)
	// 		// 	nbr = nbr << 8;
	// 	}
	// 	write(1, "\n", 1);
	// 	ft_putnbr(COREWAR_EXEC_MAGIC);
	// 	write(1, "\n", 1);
	// 	nbr = *(int*)buff;
	// 	nbr = (nbr & BYTE_1) << 24 | (nbr & BYTE_2) << 8 | (nbr & BYTE_3) >> 8 | (nbr & BYTE_4) >> 24;
	// 	j = i * 8;
	// 		while (--j >= 0)
	// 			ft_putnbr((nbr >> j) & 1);
	// 		write(1, "\n", 1);
	// 	ft_putnbr(nbr);

	// }
	
	return (0);
}
