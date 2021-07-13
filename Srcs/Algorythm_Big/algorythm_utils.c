/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:01:11 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/13 14:23:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int		find_node_pos(t_list **stack, char **move, char *denominator, int id)
{
	int		length;

	length = 0;
	if (id <= lst_len(stack) / 2)
	{
		length = id;
		(*move) = ft_strjoin("r", denominator);
	}
	else if (id > lst_len(stack) / 2)
	{
		length = lst_len(stack) - id;
		(*move) = ft_strjoin("rr", denominator);
	}
	return (length);
}