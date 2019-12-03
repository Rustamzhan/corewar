/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:12:27 by astanton          #+#    #+#             */
/*   Updated: 2019/12/03 21:32:43 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_file(char *name_file)
{
	int	fd;

	if (ft_strcmp(ft_strchr(name_file, '.'), ".cor"))
	{
		write(1, "\x1b[35m", 6);
		write(1, "\nWrong type of file.\n", 22);
		ft_print_usage_and_exit();
	}
	fd = open(name_file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "\x1b[35m", 6);
		write(1, "\nCan't open file, check filename, please.\n", 43);
		ft_print_usage_and_exit();
	}
	if (close(fd) != 0)
	{
		write(1, "\nCan't close file.\n", 20);
		write(1, "\x1b[0m", 6);
		exit(2);
	}
}

static int	ft_isnumber(char *str, int var, int *num)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (var == 1)
	{
		n = ft_atoi(str);
		if (n < 1 || n > MAX_PLAYERS || (*num >> n & 1))
		{
			write(1, "\x1b[35m", 6);
			write(1, "\nWrong champion's id.\n", 22);
			ft_print_usage_and_exit();
		}
		*num = *num | (1 << n);
	}
	return (1);
}

static void	check_arguments(int *types, char **av, int ac, int n)
{
	int	i;

	i = 0;
	if (ac == 2 && types[0] != TYPE_FILE)
		ft_print_usage_and_exit();
	while (++i < ac)
	{
		if (types[i - 1] == TYPE_OPT_DUMP && (i != 1 || ac - i - 2 < 1
			|| types[i] != TYPE_NUMBER))
			ft_print_usage_and_exit();
		else if (types[i - 1] == TYPE_OPT_DUMP)
			i++;
		if (types[i - 1] == TYPE_FILE)
			check_file(av[i]);
		else if (types[i - 1] == TYPE_OPT_N)
		{
			if (ac - i - 2 < 1 || types[i] != TYPE_NUMBER
				|| !ft_isnumber(av[i + 1], 1, &n) || types[i + 1] != TYPE_FILE)
			{
				write(1, "\x1b[35m", 6);
				write(1, "\nWrong option input.\n", 22);
				ft_print_usage_and_exit();
			}
		}
	}
}

void		verification_of_incoming_data(int ac, char **av)
{
	int	i;
	int	files;
	int	arg_types[ac - 1];

	if (ac == 1)
		ft_print_usage_and_exit();
	i = 0;
	files = 0;
	while (++i < ac)
	{
		if (!(ft_strcmp(av[i], "-n")))
			arg_types[i - 1] = TYPE_OPT_N;
		else if (!(ft_strcmp(av[i], "-dump")))
			arg_types[i - 1] = TYPE_OPT_DUMP;
		else if (ft_isnumber(av[i], 0, 0))
			arg_types[i - 1] = TYPE_NUMBER;
		else
		{
			arg_types[i - 1] = TYPE_FILE;
			files++;
		}
	}
	check_arguments(arg_types, av, ac, 0);
	check_binary_files(arg_types, av, ac, files);
}
