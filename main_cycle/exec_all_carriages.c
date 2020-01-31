/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_all_carriages.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:02:55 by astanton          #+#    #+#             */
/*   Updated: 2020/01/31 19:46:50 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	(*g_func_op[16])(t_game *game, t_carriage *carriage) = {
	&live, &ld, &st, &add, &sub, &and, &or, &xor, &zjmp, &ldi, &sti,
	&ft_fork, &lld, &lldi, &lfork, &aff};

void		exec_all_carriages(t_game *game)
{
	t_carriage	*cur;

	cur = game->carriages;
	while (cur)
	{
		if (!cur->cycles_till_exec)
		{
			cur->operation_code = game->field[cur->cur_position] - 1;
			if (cur->operation_code >= 0 && cur->operation_code < 16)
				cur->cycles_till_exec =
					g_ops[cur->operation_code].cycles_to_exec;
		}
		cur->cycles_till_exec -= (cur->cycles_till_exec) ? 1 : 0;
		if (!cur->cycles_till_exec)
		{
			if (cur->operation_code >= 0 && cur->operation_code < 16)
				g_func_op[cur->operation_code](game, cur);
			else
				cur->offset = 1;
			cur->position = (cur->position + cur->offset) % MEM_SIZE;
		}
		cur = cur->next;
	}
}
