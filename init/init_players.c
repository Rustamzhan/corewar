/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:43:40 by astanton          #+#    #+#             */
/*   Updated: 2019/12/08 00:31:30 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		take_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "\x1b[35m", 6);
		write(1, "\nCan't open file, check filename, please.\n", 43);
		ft_print_usage_and_exit();
	}
	return (fd);
}

static t_player	*fill_player(char *file_name, int id)
{
	t_player	*player;
	int			fd;

	fd = take_fd(file_name);
	player = (t_player*)malloc(sizeof(t_player));
	if (!player)
	{
		write(1, "\x1b[35m", 6);
		write(1, "\nMemory for player is not allocated.\n", 37);
		write(1, "\x1b[0m", 6);
		exit(4);
	}
	player->name = save_name(fd);
	player->size_of_code = save_size_of_code(fd);
	player->comment = save_comment(fd);
	player->code = save_exec_code(fd, player->size_of_code);
	player->player_id = id;
	player->prev = NULL;
	return (player);
}

static int		find_number(char check)
{
	int	i;

	i = 4;
	while (i > 0)
	{
		if (!(check & (1 << i)))
			return (i);
		i--;
	}
	return (0);
}

static void		refill_champs_id(t_player *players)
{
	char		check;
	int			i;
	int			n;
	t_player	*tmp;

	check = 0;
	tmp = players;
	while (tmp)
	{
		if (tmp->player_id)
			check = check | (1 << tmp->player_id);
		tmp = tmp->next;
	}
	tmp = players;
	i = 0;
	while (tmp)
	{
		if (!tmp->player_id)
		{
			n = find_number(check);
			tmp->player_id = n;
			check = check | (1 << n);
		}
		tmp = tmp->next;
	}
}

t_player		*init_players(int ac, char **av)
{
	t_player	*players;
	t_player	*tmp;
	int			i;
	int			champ_id;

	i = 0;
	players = NULL;
	while (++i < ac)
	{
		champ_id = 0;
		if (i == 1 && !ft_strcmp(av[i], "-dump"))
			i += 2;
		if (!ft_strcmp(av[i], "-n"))
		{
			champ_id = ft_atoi(av[++i]);
			i++;
		}
		tmp = fill_player(av[i], champ_id);
		tmp->next = players;
		if (players)
			players->prev = tmp;
		players = tmp;
	}
	refill_champs_id(players);
	return (players);
}
