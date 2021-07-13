/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:30:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/13 12:51:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

// char	**calc_order_moves(t_list **stack)
// {
// 	t_list	*iterator;
// 	char	**final_moves;
// 	char	*move;
// 	int		length;
// 	int		biggest_id;

// 	iterator = *stack;
// 	length = 0;
// 	biggest_id = 0;
// 	//find biggest value;
// 	while (iterator)
// 	{
// 		if (iterator->value > biggest_id)
// 			biggest_id = iterator->value;
// 		iterator = iterator->next;
// 	}
// 	biggest_id = get_id(*stack, biggest_id)
// 	//if biggest value in head register rb
// 	if (biggest_id <= (lst_len(stack) / 2)
// 	//if biggest value in tail register rrb
// 	//return moves
// }

int		check_order(t_list **stack)
{
	t_list	*iterator;

	iterator = *stack;
	while (iterator->next)
	{
		if (iterator->value < iterator->next->value)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}

char	**calc_final_moves(t_list **stack)
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
