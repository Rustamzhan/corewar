/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:34:44 by astanton          #+#    #+#             */
/*   Updated: 2020/01/10 18:55:11 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// int		get_int(unsigned char *arg_field)
// {
// 	int	num;

// 	num = (int)arg_field;
// 	num = (num & BYTE_1) << 24 | (num & BYTE_2) << 8
// 		| (num & BYTE_3) >> 8 | (num & BYTE_4) >> 24;
// 	return (num);
// }

void	live(t_game *game, t_carriage *carriage)
{
	unsigned char	result[DIR_SIZE];
	int				argument;
	int				i;
	int				pos;

	i = DIR_SIZE;
	pos = carriage->position + 1;
	while (--i >= 0)
	{
		result[i] = game->field[pos % MEM_SIZE];
		pos++;
	}
	argument = *((int *)result);
	if (argument > -5 && argument < 0)
	{
		game->last_survivor = argument;
		// write(1, "Player ", 7);
		// ft_putnbr(argument);
		// write(1, " is said to be alive\n", 21);
	}
	carriage->last_live_cycle = game->current_cycle;
	game->number_of_live_instructions++;
}
