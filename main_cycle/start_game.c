/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:52:50 by astanton          #+#    #+#             */
/*   Updated: 2020/01/31 19:57:22 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	start_game_simple(t_game *game)
{
	int	cycle;

	cycle = (game->dump) ? game->dump_cycles : 1;
	while (cycle)
	{
		cycle -= game->dump;
		game->current_cycle++;
		exec_all_carriages(game->carriages);
	}
}

void		start_game(t_game game)
{
	introducing_players(game.players);
	if (game.visualization)
		start_game_with_visual();
	else
		start_game_simple(&game);
}
