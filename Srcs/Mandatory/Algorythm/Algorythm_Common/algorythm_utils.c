/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:01:11 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/29 17:05:50 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

int	check_order(t_list **stack)
{
	t_list	*iterator;

	iterator = *stack;
	while (iterator->next)
	{
		if (iterator->value > iterator->next->value)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}

int	find_node_pos(t_list **stack, char **move, char *denominator, int id)
{
	int		length;

	length = 0;
	if (id <= struct_len(stack) / 2)
	{
		length = id;
		(*move) = ft_strjoin("r", denominator);
	}
	else if (id > struct_len(stack) / 2)
	{
		length = struct_len(stack) - id;
		(*move) = ft_strjoin("rr", denominator);
	}
	return (length);
}

char	**fill_moves(char *fill, int length)
{
	int		i;
	char	**moves;

	i = 0;
	moves = (char **)malloc((length + 1) * sizeof(char *));
	if (!moves)
		return (NULL);
	moves[length] = NULL;
	while (i < length)
	{
		moves[i] = ft_strdup(fill);
		i++;
	}
	return (moves);
}

char	**tabjoin_free(char **tab1, char **tab2, int freetab)
{
	char	**result;

	result = ft_tabjoin(tab1, tab2);
	if (freetab == 1)
		ft_freetab(tab1);
	if (freetab == 2)
		ft_freetab(tab2);
	if (freetab == 3)
	{
		ft_freetab(tab1);
		ft_freetab(tab2);
	}
	return (result);
}
