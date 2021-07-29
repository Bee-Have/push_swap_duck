/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:30:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/29 17:06:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

char	**calc_order_moves(t_list **stack)
{
	char	**final_moves;
	char	*move;
	int		length;
	int		i;
	int		biggest_id;

	length = 0;
	i = 0;
	biggest_id = get_id(*stack, get_biggest_value(stack));
	length = find_node_pos(stack, &move, "b", biggest_id);
	final_moves = (char **)malloc((length + 1) * sizeof(char *));
	if (!final_moves)
		return (NULL);
	final_moves[length] = NULL;
	while (i < length)
	{
		final_moves[i] = ft_strdup(move);
		i++;
	}
	free(move);
	return (final_moves);
}

char	**big_final_moves(t_list **stack)
{
	t_list	*iterator;
	char	**moves;
	int		length;
	int		i;

	iterator = *stack;
	length = 0;
	i = 0;
	while (iterator)
	{
		length++;
		iterator = iterator->next;
	}
	moves = (char **)malloc((length + 1) * sizeof(char *));
	if (!moves)
		return (NULL);
	moves[length] = NULL;
	while (i < length)
	{
		moves[i] = ft_strdup("pa");
		i++;
	}
	return (moves);
}
