/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:43:40 by astanton          #+#    #+#             */
/*   Updated: 2020/01/31 17:10:12 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		open_close_fd(char *file, int var, int close_fd)
{
	int	fd;

	if (var == 1)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			write(1, "\x1b[35m", 6);
			write(1, "\nCan't open file, check filename, please.\n", 43);
			ft_print_usage_and_exit();
		}
		return (fd);
	}
	else
	{
		if (close(close_fd))
		{
			write(1, "\x1b[35m", 6);
			write(1, "\nCan't close file.\n", 20);
			write(1, "\x1b[0m", 6);
			exit(2);
		}
	}
	return (-1);
}

static t_player	*fill_player(char *file_name, int id)
{
	t_player	*player;
	int			fd;

	fd = open_close_fd(file_name, 1, 0);
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
	player->next = NULL;
	open_close_fd(file_name, 2, fd);
	return (player);
}

static int		find_number(char check)
{
	int	i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		if (!(check & (1 << i)))
			return (i);
		i++;
	}
	return (0);
}

static char		refill_champs_id(t_player *players)
{
	char		check;
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
	return (check);
}

t_player		*init_players(int ac, char **av, t_game *game)
{
	t_player	*players;
	t_player	*tmp;
	int			i;
	int			champ_id;

	i = ac - 1;
	players = NULL;
	while (i > 0 && ft_strcmp(av[i - 1], "-dump") && ft_strcmp(av[i], "-v"))
	{
		champ_id = (i > 2 && !ft_strcmp(av[i - 2], "-n")) ?
			ft_atoi(av[i - 1]) : 0;
		tmp = fill_player(av[i], champ_id);
		tmp->next = players;
		(players) ? players->prev = tmp : 0;
		players = tmp;
		i -= (i > 2 && (!ft_strcmp(av[i - 2], "-n")
			|| !ft_strcmp(av[i - 2], "-dump"))) ? 3 : 1;
	}
	game->players_id = refill_champs_id(players);
	return (players);
}
