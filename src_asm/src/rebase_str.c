/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:13:59 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 19:55:58 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*rebase_str_first_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	result = NULL;
	str_cat = NULL;
	temp = NULL;
	temp1 = NULL;
	temp = ft_strchr(content, 37);
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, ",");
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}

char	*rebase_str_second_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	result = NULL;
	str_cat = NULL;
	temp = NULL;
	temp1 = NULL;
	temp = ft_strchr(content, 58) + 1;
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, ",");
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}

char	*rebase_str_third_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	result = NULL;
	str_cat = NULL;
	temp = NULL;
	temp1 = NULL;
	temp = ft_strchr(content, 35);
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, ",");
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}

char	*rebase_str_fourth_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	result = NULL;
	str_cat = NULL;
	temp = NULL;
	temp1 = NULL;
	temp = ft_strchr(content, 59);
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, ",");
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}

char	*rebase_str_fifth_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	result = NULL;
	str_cat = NULL;
	temp = NULL;
	temp1 = NULL;
	temp = ft_strchr(content, 58) + 1;
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, ",");
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}
