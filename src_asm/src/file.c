/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:12:24 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 19:43:37 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_output_str(t_asm_content **content)
{
	write(1, "Writing output program to ", 26);
	write(1, (*content)->new_filename, ft_strlen((*content)->new_filename));
	write(1, "\n", 1);
}

static int	check_slashn_end(const char *filename, t_asm_content **content)
{
	int		fd;
	int		i;
	char	slash_n;

	fd = 0;
	if (!(fd = open(filename, O_RDONLY)))
		error(*content);
	slash_n = 0;
	i = 0;
	while (slash_n != '\n' && lseek(fd, --i, SEEK_END) != -1L)
	{
		if (read(fd, &slash_n, 1) < 0)
			error(*content);
		if (slash_n != ' ' && slash_n != '\f' &&
			slash_n != '\n' && slash_n != '\t' &&
			slash_n != '\r' && slash_n != '\v')
			error(*content);
	}
	return (1);
}

int			create_f(const char *filename, int only_name_len, char *file_type,
														t_asm_content **content)
{
	char	*new_filename;
	int		type_len;

	type_len = file_type[1] == 's' ? EXP_ASM_LEN : EXP_COR_LEN;
	*content = init_content(file_type[1]);
	new_filename = (char *)ft_memalloc((only_name_len + type_len + 1) *
																sizeof(char));
	(*content)->new_filename = ft_strcat(ft_memcpy(new_filename, filename,
													only_name_len), file_type);
	file_type[1] == 'c' ? check_slashn_end(filename, content) : 1;
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error(*content);
	return (1);
}

int			file(const char *filename, t_asm_content **content)
{
	int		filename_len;
	int		only_name_len;

	filename_len = 0;
	if (!filename || (filename_len = ft_strlen(filename)) == 0 ||
								ft_strrchr(filename, '.') == NULL)
		error(*content);
	only_name_len = filename_len - ft_strlen(ft_strrchr(filename, '.'));
	if (!ft_strcmp((filename + only_name_len), EXP_ASM) && only_name_len > 0)
		create_f(filename, only_name_len, EXP_COR, content);
	else if (!ft_strcmp((filename + only_name_len), EXP_COR) && \
	only_name_len > 0)
		create_f(filename, only_name_len, EXP_ASM, content);
	else
		error(*content);
	return (1);
}
