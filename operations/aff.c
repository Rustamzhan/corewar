/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:59:08 by astanton          #+#    #+#             */
/*   Updated: 2020/02/05 03:07:34 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	aff(t_game *game, t_carriage *carriage)
{
	char	c;

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	c = carriage->reg[carriage->args[0]] % 256;
	write(2, &c, 1);
}
