/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:18:41 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/26 18:27:59 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

void	small_manager(t_list **stack_a, t_list **stack_b)
{
	int		total_moves;
	char	**moves;
	
	total_moves = 0;
	while (check_order(stack_a) == 1 || stack_b)
	{
		if (struct_len(stack_a) > 3)
			moves = get_smallest_value_out(stack_a, "a");
		else
			moves = small_sorting_moves(stack_a);
		if (check_order(stack_a) == 1)
			execute_actions(stack_a, stack_b, moves);
		total_moves += ft_tablen((const char **)moves);
	}
	if (check_order(stack_a) == 1)
	{
		printf("list has not been sorted\n");
		error_message();
	}
	free(moves);
}

char	**get_smallest_value_out(t_list **stack, char *denominator)
{
	char	**final_moves;
	char	*move;
	int		length;
	int		i;

	i = 0;
	//find number or ra/rra to get it out
	length = find_node_pos(stack, &move, denominator, get_smallest(stack));
	//for each number, malloc char **
	final_moves = (char **)malloc((length + 2) * sizeof(char *));
	if (!final_moves)
		return (NULL);
	final_moves[length] = NULL;
	//fill it with either ra | rra
	while (i < length)
	{
		final_moves[i] = ft_strdup(move);
		i++;
	}
	//add final pb
	final_moves[i] = ft_strdup("pb");
	//return char **
	return (final_moves);
}

char	**small_sorting_moves(t_list **stack)
{
	char	**moves;

	moves = (char **)malloc(2 * sizeof(char *));
	if (!moves)
		return (NULL);
	moves[1] = NULL;
	if ((*stack)->next->value < (*stack)->value)
		moves[0] = ft_strdup("sa");
	else if ((*stack)->next->value > (*stack)->value)
	{
		if ((*stack)->next->value == get_biggest_value(stack))
			moves[0] = ft_strdup("ra");
		if ((*stack)->next->value != get_biggest_value(stack))
			moves[0] = ft_strdup("rra");
	}
	return (moves);
}

char	**small_final_moves(t_list **stack)
{
	char	**moves;
	
	moves = (char **)malloc(2 * sizeof(char *));
	if (!moves)
		return (NULL);
	moves[1] = NULL;
	if (!(*stack)->next || (*stack)->value > (*stack)->next->value)
		moves[0] = ft_strdup("pa");
	else
		moves[0] = ft_strdup("sa");
	return (moves);
}
