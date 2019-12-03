/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:13:55 by astanton          #+#    #+#             */
/*   Updated: 2019/12/03 21:26:32 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_usage_and_exit(void)
{
	write(1, "\x1b[31m", 6);
	write(1, "\n", 1);
	write(1, "Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] \
...\n", 69);
	write(1, "\n", 1);
	write(1, "  -dump nbr_cycles : Dumps memory after nbr_cycles cycles \
then exits\n", 70);
	write(1, "  -n	number	   : Sets the number of the next player, \
where 0 < n < ", 68);
	ft_putnbr(MAX_PLAYERS + 1);
	write(1, "\x1b[0m", 6);
	write(1, "\n\n", 2);
	exit(1);
}

void	ft_print_message_wrong_exec_size(char *file)
{
	write(1, "\x1b[35m", 6);
	write(1, "\nWrong size of champions exec code in file : ", 46);
	write(1, file, ft_strlen(file));
	write(1, "\x1b[0m", 6);
	write(1, "\n", 1);
	exit(3);
}

void	ft_print_message_wrong_null_marker(char *file)
{
	write(1, "\x1b[35m", 6);
	write(1, "\nWrong binary format, NULL marker is missing or in the \
wrong place in file : ", 78);
	write(1, file, ft_strlen(file));
	write(1, "\x1b[0m", 6);
	write(1, "\n", 1);
	exit(3);
}
