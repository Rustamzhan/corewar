/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolowercase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:09:53 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:54:05 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*ft_to_lower_case(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
	return (str);
}
