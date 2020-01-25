/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:32:07 by astanton          #+#    #+#             */
/*   Updated: 2020/01/10 20:39:11 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op	op_tab[16] =
{
	{1, {T_DIR}, 10, 0},
	{2, {T_DIR | T_IND, T_REG}, 5, 1},
	{2, {T_REG, T_IND | T_REG}, 5, 1},
	{3, {T_REG, T_REG, T_REG}, 10, 1},
	{3, {T_REG, T_REG, T_REG}, 10, 1},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1},
	{1, {T_DIR}, 20, 0},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, 1},
	{3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, 1},
	{1, {T_DIR}, 800, 0, 1},
	{2, {T_DIR | T_IND, T_REG}, 10, 1},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, 1},
	{1, {T_DIR}, 1000, 0},
	{1, {T_REG}, 2, 1},
};
