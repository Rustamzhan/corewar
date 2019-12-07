/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:23:38 by astanton          #+#    #+#             */
/*   Updated: 2019/12/08 00:32:18 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void print_memory(unsigned char *str)
{
	int		i;
	int		j;
	char	*hex = "0123456789abcdef";
	char	dst[12865];

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
		if (i % LINE_LENGTH == LINE_LENGTH - 1)
			dst[j++] = '\n';
		else
			dst[j++] = ' ';
		i++;
	}
	dst[j] = '\0';
	write(1, dst, 12865);
}

static void	print_player(t_player *player)
{
	t_player *tmp;
	int	i;
	char	*hex = "0123456789abcdef";

	tmp = player;
	while (tmp->next)
		tmp = tmp->next;
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
		ft_putnbr(tmp->player_id);
		write(1, "\n", 1);
		ft_putnbr(tmp->size_of_code);
		write(1, "\n", 1);
		write(1, "\n", 1);
		tmp = tmp->prev;
	}
}

void debug(void *arg, int var)
{
	if (var == 1)
		print_memory((unsigned char *)arg);
	if (var == 2)
		print_player((t_player*) arg);
}
