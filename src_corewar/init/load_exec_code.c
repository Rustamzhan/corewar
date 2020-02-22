/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_exec_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:25:54 by astanton          #+#    #+#             */
/*   Updated: 2020/02/04 16:09:18 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	find_size_of_champ_field(t_player *players)
{
	int			champs;
	t_player	*tmp;

	tmp = players;
	champs = 0;
	while (tmp)
	{
		champs++;
		tmp = tmp->next;
	}
	return ((MEM_SIZE) / champs);
}

void		load_exec_code_in_battle_field(t_game game, t_player *players)
{
	t_player		*tmp;
	unsigned char	*field;
	int				one_champ_size;

	tmp = players;
	while (tmp->next)
		tmp = tmp->next;
	field = game.field;
	one_champ_size = find_size_of_champ_field(players);
	while (tmp)
	{
		ft_memcpy(field, tmp->code, tmp->size_of_code);
		field += one_champ_size;
		tmp = tmp->prev;
	}
}
