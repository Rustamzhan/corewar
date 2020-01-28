/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:34:44 by astanton          #+#    #+#             */
/*   Updated: 2020/01/28 18:57:42 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_game *game, t_carriage *carriage)
{
	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	if (game->players_id & (1 << carriage->args[0]))
		game->last_survivor = carriage->args[0];
	carriage->last_live_cycle = game->current_cycle;
	game->number_of_live_instructions += 1;
}
