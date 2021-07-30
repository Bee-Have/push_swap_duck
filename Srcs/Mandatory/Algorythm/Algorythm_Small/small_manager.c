/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:18:41 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/30 16:42:54 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

void	small_manager(t_list **stack_a, t_list **stack_b)
{
	int		total_moves;
	char	**moves;

	total_moves = 0;
	while (check_order(stack_a) == 1)
	{
		if (struct_len(stack_a) > 3)
			moves = get_smallest_value_out(stack_a, "a");
		else
			moves = small_sorting_moves(stack_a);
		execute_actions(stack_a, stack_b, moves);
		total_moves += ft_tablen((const char **)moves);
	}
	while ((*stack_b))
	{
		moves = small_final_moves(stack_b);
		execute_actions(stack_a, stack_b, moves);
		total_moves += ft_tablen((const char **)moves);
	}
	if (check_order(stack_a) == 1)
		error_message();
	// print_struct(*stack_a);
	free(moves);
}

char	**get_smallest_value_out(t_list **stack, char *denominator)
{
	char	**final_moves;
	char	*move;
	int		length;
	int		i;

	i = 0;
	length = find_node_pos(stack, &move, denominator, get_smallest(stack));
	final_moves = (char **)malloc((length + 1) * sizeof(char *));
	if (!final_moves)
		return (NULL);
	final_moves[length] = NULL;
	while (i < length)
	{
		final_moves[i] = ft_strdup(move);
		i++;
	}
	final_moves = ft_add_tab(final_moves, "pb");
	return (final_moves);
}

char	**small_sorting_moves(t_list **stack)
{
	char	**moves;

	moves = NULL;
	if ((*stack)->value == get_biggest_value(stack)
		&& (*stack)->next->value == get_node_value(stack, get_smallest(stack)))
		moves = ft_add_tab(NULL, "ra");
	else if ((*stack)->value == get_node_value(stack, get_smallest(stack))
		&& (*stack)->next->value == get_biggest_value(stack))
		moves = ft_add_tab(NULL, "rra");
	else if ((*stack)->value > (*stack)->next->value)
		moves = ft_add_tab(NULL, "sa");
	else
	{
		if ((*stack)->next->value == get_biggest_value(stack))
			moves = ft_add_tab(NULL, "rra");
		if ((*stack)->value == get_node_value(stack, get_smallest(stack)))
			moves = ft_add_tab(NULL, "ra");
	}
	return (moves);
}

char	**small_final_moves(t_list **stack)
{
	t_list	*tmp;
	char	**moves;

	if (!stack)
		return (NULL);
	tmp = *stack;
	if (tmp->next == NULL)
		moves = ft_add_tab(NULL, "pa");
	else if (tmp->value < tmp->next->value)
		moves = ft_add_tab(NULL, "sb");
	else
		moves = ft_add_tab(NULL, "pa");
	return (moves);
}
