/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:14:30 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 22:20:33 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		regex_init(t_asm_content *content)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!(fd = open("src_asm/regex", O_RDONLY)))
		error(content);
	while (get_next_line(fd, &line) > 0 && i < 8)
		content->reg[i++] = line;
	close(fd);
}

static void		init_header(t_header **header, t_asm_content *content)
{
	if (!(*header = (t_header *)ft_memalloc(sizeof(t_header))))
		error(content);
	(*header)->magic = COREWAR_EXEC_MAGIC;
	regex_init(content);
}

t_asm_content	*init_content(char ad_flag)
{
	t_asm_content	*content;

	if (!(content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content))))
		error(content);
	content->fd_dst = 0;
	content->fd_src = 0;
	content->asm_dsm_flag = ad_flag;
	content->flag_name = 0;
	content->flag_comment = 0;
	content->flag_pattern = 0;
	content->memory_code_size = 0;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	content->exec_code_size = 0;
	content->bytecode = NULL;
	content->asm_size = 0;
	content->buf = NULL;
	content->new_filename = NULL;
	content->b_pos = 0;
	content->header_size = HEADER_SIZE;
	init_header(&content->header, content);
	return (content);
}
