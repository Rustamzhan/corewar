/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:13:26 by astanton          #+#    #+#             */
/*   Updated: 2020/01/26 23:31:35 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	get_offset(int *args, int op_code)
{
	int	offset;
	int i;

	offset = 1;
	i = 0;
	while (i < g_ops[op_code].num_of_args)
	{
		if (args[i] == T_DIR)
			offset += g_ops[op_code].dir_size;
		else if (args[i] == T_REG)
			offset += 1;
		else
			offset += 2;
		i++;
	}
	offset += g_ops[op_code].args_byte;
	return (offset);
}
