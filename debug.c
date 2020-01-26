/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:23:38 by astanton          #+#    #+#             */
/*   Updated: 2020/01/26 23:02:11 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	introducing(t_player *players)
{
	t_player	*tmp;

	tmp = players;
	write(1, "Introducing contestants...\n", 27);
	while (tmp)
	{
		write(1, "* Player ", 9);
		ft_putnbr(tmp->player_id);
		write(1, ", weighing ", 11);
		ft_putnbr(tmp->size_of_code);
		write(1, " bytes, \"", 9);
		write(1, tmp->name, ft_strlen(tmp->name));
		write(1, "\" (\"", 4);
		write(1, tmp->comment, ft_strlen(tmp->comment));
		write(1, "\") !\n", 5);
		tmp = tmp->next;
	}
}

static void print_memory(unsigned char *str)
{
	int		i;
	int		j;
	char	*hex = "0123456789abcdef";
	char	dst[12928];

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		if (i % LINE_LENGTH == 0)
		{
			dst[j++] = '0';
			dst[j++] = 'x';
			dst[j++] = hex[(i >> 12) & 0xf];
			dst[j++] = hex[(i >> 8) & 0xf];
			dst[j++] = hex[(i >> 4) & 0xf];
			dst[j++] = hex[i & 0xf];
			dst[j++] = ' ';
			dst[j++] = ':';
			dst[j++] = ' ';
		}
		dst[j++] = hex[(str[i] >> 4) & 0xf];
		dst[j++] = hex[str[i] & 0xf];
		dst[j++] = ' ';
		if (i % LINE_LENGTH == LINE_LENGTH - 1)
			dst[j++] = '\n';
		i++;
	}
	dst[j] = '\0';
	write(1, dst, 12928);
}

static void	print_player(t_player *player)
{
	t_player *tmp;
	int	i;
	char	*hex = "0123456789abcdef";

	tmp = player;
	while (tmp)
	{
		write(1, tmp->name, ft_strlen(tmp->name));
		write(1, "\n", 1);
		write(1, tmp->comment, ft_strlen(tmp->comment));
		write(1, "\n", 1);
		i = 0;
		while (i < tmp->size_of_code)
		{
			write(1, &hex[(tmp->code[i] >> 4) & 0xf], 1);
			write(1, &hex[tmp->code[i] & 0xf], 1);
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		write(1, "Player id : ", 12);
		ft_putnbr(tmp->player_id);
		write(1, "\n", 1);
		write(1, "Size of code : ", 15);
		ft_putnbr(tmp->size_of_code);
		write(1, "\n", 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

static void	print_int_binary(int n)
{
	int i;

	i = 31;
	while (i >= 0)
	{
		ft_putnbr((n >> i) & 1);
		i--;
	}
	write(1, "\n", 1);
}

static void print_carriages(t_carriage *carriages)
{
	int	i;

	while(carriages)
	{
		write(1, "id : ", 5);
		ft_putnbr(carriages->id);
		write(1, "\n", 1);
		write(1, "carry : ", 8);
		ft_putnbr(carriages->carry);
		write(1, "\n", 1);
		write(1, "operation code : ", 17);
		ft_putnbr(carriages->operation_code);
		write(1, "\n", 1);
		write(1, "last_live_cycle : ", 18);
		ft_putnbr(carriages->last_live_cycle);
		write(1, "\n", 1);
		write(1, "cycles_till_exec : ", 18);
		ft_putnbr(carriages->cycles_till_exec);
		write(1, "\n", 1);
		write(1, "step : ", 7);
		ft_putnbr(carriages->offset);
		write(1, "\n", 1);
		write(1, "position : ", 11);
		ft_putnbr(carriages->position);
		write(1, "\n", 1);
		write(1, "reg : [", 7);
		i = 0;
		while(i < REG_NUMBER){
			ft_putnbr(carriages->reg[i]);
			if (i < REG_NUMBER - 1)
				write(1, ", ", 2);
			i++;
		}
		write(1, "]\n", 2);
		write(1, "\n", 1);
		carriages = carriages->next;
	}
}

void	print_game(t_game *game)
{
	write(1, "last survivor : ", 16);
	ft_putnbr(game->last_survivor);
	write(1, "\n", 1);
	write(1, "current cycle : ", 16);
	ft_putnbr(game->current_cycle);
	write(1, "\n", 1);
	write(1, "number of live instructions : ", 30);
	ft_putnbr(game->number_of_live_instructions);
	write(1, "\n", 1);
	write(1, "cycles to die : ", 16);
	ft_putnbr(game->cycles_to_die);
	write(1, "\n", 1);
	write(1, "number of checks : ", 19);
	ft_putnbr(game->number_of_checks);
	write(1, "\n", 1);
	print_memory(game->field);
}

void	debug(void *arg, void *arg2, int var)
{
	if (var == 1)
	{
		introducing((t_player *)arg2);
		print_memory((unsigned char *)arg);
	}
	if (var == 2)
		print_player((t_player*) arg);
	if (var == 3)
		print_int_binary(*((int *)arg));
	if (var == 4)
		print_carriages((t_carriage *)arg2);
	if (var == 5)
		print_game((t_game *)arg);
}

