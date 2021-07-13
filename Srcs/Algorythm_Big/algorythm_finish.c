/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:30:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/13 14:53:47 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int		check_order(t_list **stack)
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

char	**calc_order_moves(t_list **stack)
{
	t_list	*iterator;
	char	**final_moves;
	char	*move;
	int		length;
	int		i;
	int		biggest_id;

	iterator = *stack;
	length = 0;
	i = 0;
	biggest_id = 0;
	//find biggest value;
	while (iterator)
	{
		if (iterator->value > biggest_id)
			biggest_id = iterator->value;
		iterator = iterator->next;
	}
	printf("biggest_value-[%d]\n", biggest_id);
	biggest_id = get_id(*stack, biggest_id);
	printf("biggest_id-[%d]\n", biggest_id);
	//if biggest value in head register rb
	//if biggest value in tail register rrb
	length = find_node_pos(stack, &move, "b", biggest_id);
	//allocate moves
	final_moves = (char **)malloc((length + 1) * sizeof(char *));
	if (!final_moves)
		return (NULL);
	//fill up move {char **}
	final_moves[length] = NULL;
	while (i < length)
	{
		final_moves[i] = ft_strdup(move);
		i++;
	}
	//return moves
	printf("final moves for right order : \n");
	ft_print_tab(final_moves);
	return (final_moves);
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
