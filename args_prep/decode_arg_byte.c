/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_arg_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:11:30 by astanton          #+#    #+#             */
/*   Updated: 2020/01/26 22:11:19 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	*decode_arg_byte(unsigned char byte, int op_code)
{
	int	args[4];
	int	i;
	int	move;

	if (!g_ops[op_code].args_byte)
		return (g_ops[op_code].arg_types);
	move = 6;
	i = 0;
	while (i < 4)
	{
		args[i] = (byte >> move) & 3;
		if (args[i] == REG_CODE)
			args[i] = T_REG;
		else if (args[i] == DIR_CODE)
			args[i] = T_DIR;
		else if (args[i] == IND_CODE)
			args[i] = T_IND;
		else
			args[i] = 0;
		move -= 2;
		i++;
	}
	return (args);
}
