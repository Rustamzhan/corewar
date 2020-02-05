/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:52:50 by astanton          #+#    #+#             */
/*   Updated: 2020/02/05 04:46:18 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <ncurses.h>

static void	print_field(unsigned char *field, char *dst)
{
	int		i;
	int		j;
	char	*hex;

	i = 0;
	j = 0;
	hex = "0123456789abcdef";
	while (i < MEM_SIZE)
	{
		dst[j++] = hex[(field[i] >> 4) & 0xf];
		dst[j++] = hex[field[i] & 0xf];
		dst[j++] = ' ';
		if (i % LINE_LENGTH == LINE_LENGTH - 1)
			dst[j++] = '\n';
		i++;
	}
	dst[j] = '\0';
}

static void	start_game_with_visual(t_game *game)
{
	char *dst;
	WINDOW *win;

	dst = malloc(12928);
	initscr();
	win = newwin(192, 192, 0, 0);
	if (!game)
		exit(1);
	while (game->carriages)
	{
		game->current_cycle++;
		exec_all_carriages(game);
		print_field(game->field, dst);
		waddstr(win, dst);
		wrefresh(win);
		if (game->current_cycle - game->last_check_cycle >= game->cycles_to_die
			|| game->cycles_to_die <= 0)
		{
			game->last_check_cycle = game->current_cycle;
			check_carriages(game);
			game->number_of_checks++;
			if (game->number_of_live_instructions >= NBR_LIVE
				|| game->number_of_checks == MAX_CHECKS)
			{
				game->cycles_to_die -= CYCLE_DELTA;
				game->number_of_checks = 0;
			}
			game->number_of_live_instructions = 0;
		}
	}
	endwin();
}

static void	start_game_simple(t_game *game)
{
	int	cycle;

	cycle = (game->dump) ? game->dump_cycles : 1;
	while (cycle && game->carriages)
	{
		cycle -= game->dump;
		game->current_cycle++;
		exec_all_carriages(game);
		if (game->current_cycle - game->last_check_cycle >= game->cycles_to_die
			|| game->cycles_to_die <= 0)
		{
			game->last_check_cycle = game->current_cycle;
			check_carriages(game);
			game->number_of_checks++;
			if (game->number_of_live_instructions >= NBR_LIVE
				|| game->number_of_checks == MAX_CHECKS)
			{
				game->cycles_to_die -= CYCLE_DELTA;
				game->number_of_checks = 0;
			}
			game->number_of_live_instructions = 0;
		}
	}
	(!game->carriages) ? print_winner(game) : dump_field(game->field);
}

void		start_game(t_game *game)
{
	if (game->visualization)
		start_game_with_visual(game);
	else
	{
		introducing_players(game->players);
		start_game_simple(game);
	}
}
