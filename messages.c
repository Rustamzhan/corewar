/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:13:55 by astanton          #+#    #+#             */
/*   Updated: 2020/01/10 17:55:29 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_usage_and_exit(void)
{
	write(1, "\x1b[31m", 5);
	write(1, "\n", 1);
	write(1, "Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] \
...\n", 68);
	write(1, "\n", 1);
	write(1, "  -dump nbr_cycles : Dumps memory after nbr_cycles cycles \
then exits\n", 69);
	write(1, "  -n	number	   : Sets the number of the next player, \
where 0 < n < ", 67);
	ft_putnbr(MAX_PLAYERS + 1);
	write(1, "\x1b[0m", 4);
	write(1, "\n\n", 2);
	exit(1);
}

void	ft_print_message_wrong_exec_size(char *file)
{
	write(1, "\x1b[35m", 5);
	write(1, "\nWrong size of champions exec code in file : ", 45);
	write(1, file, ft_strlen(file));
	write(1, "\x1b[0m", 4);
	write(1, "\n", 1);
	exit(3);
}

void	ft_print_message_wrong_null_marker(char *file)
{
	write(1, "\x1b[35m", 5);
	write(1, "\nWrong binary format, NULL marker is missing or in the \
wrong place in file : ", 77);
	write(1, file, ft_strlen(file));
	write(1, "\x1b[0m", 4);
	write(1, "\n", 1);
	exit(3);
}
