/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:46:06 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 19:48:41 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*label_validation(t_token *pointer, char *content)
{
	char		*temp;
	char		*temp1;

	temp = NULL;
	temp1 = NULL;
	if (!ft_strcmp(pointer->type, LABEL_NAME) && parse(content, DIRECT_LABEL) \
	&& !ft_strcmp((temp = ft_strsub(pointer->content, 0, strlen(\
	pointer->content) - 1)), (temp1 = ft_strsub(content, 2, strlen(content)))))
	{
		ft_strdel(&temp);
		ft_strdel(&temp1);
		return (content);
	}
	else if (!ft_strcmp(pointer->type, LABEL_NAME) && parse(content,\
	INDIRECT_LABEL) && !ft_strcmp((temp = ft_strsub(pointer->content, 0,\
	strlen(pointer->content) - 1)), (temp1 = ft_strsub(content, 1, \
	strlen(content)))))
	{
		ft_strdel(&temp);
		ft_strdel(&temp1);
		return (content);
	}
	ft_strdel(&temp);
	ft_strdel(&temp1);
	return (NULL);
}

int		check_all_label_size(t_token *pointer, t_asm_content **struct_content,\
int flag)
{
	if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
	{
		if (check(pointer))
			(*struct_content)->memory_code_size += ONE_BYTE;
		if (check_t_dir_size(pointer))
			flag = 1;
		(*struct_content)->memory_code_size += ONE_BYTE;
	}
	else if (!ft_strcmp(pointer->type, REGISTER_NAME))
		(*struct_content)->memory_code_size += ONE_BYTE;
	else if (!ft_strcmp(pointer->type, INDIRECT_NAME) || \
	!ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
		(*struct_content)->memory_code_size += TWO_BYTE;
	else if (!ft_strcmp(pointer->type, DIRECT_NAME) || \
	!ft_strcmp(pointer->type, DIRECT_LABEL_NAME))
		(*struct_content)->memory_code_size += flag ? FOUR_BYTE : TWO_BYTE;
	pointer->memory_size = (*struct_content)->memory_code_size;
	return (flag);
}
