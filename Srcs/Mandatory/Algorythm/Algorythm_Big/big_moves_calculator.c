/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_moves_calculator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:44:04 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/26 18:19:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

char	**big_moves_manager(t_list **stack_a, t_list **stack_b)
{
	t_list	*iterator;
	char	**best_moves;
	char	**moves_a;
	char	**moves_b;
	char	**both_moves;

	iterator = *stack_a;
	best_moves = NULL;
	while (iterator)
	{
		moves_b = big_moves_stack(stack_b
				, get_best_B_id(stack_b, iterator->value), "b");
		moves_a = big_moves_stack(stack_a, iterator->id, "a");
		both_moves = big_common_moves(moves_a, moves_b);
		if (!best_moves || ft_tablen((const char **)both_moves)
			< ft_tablen((const char **)best_moves))
			best_moves = both_moves;
		free(moves_a);
		free(moves_b);
		iterator = iterator->next;
	}
	return (best_moves);
}

char	**big_moves_stack(t_list **stack, int id, char *denominator)
{
	char	**result;
	char	*move;
	int		length;
	int		i;

	if (!(*stack))
		return (ft_make_tab(NULL));
	if (id == 0 && ft_strcmp(denominator, "a") == 0 && !(*stack)->next)
		return (ft_make_tab("pb"));
	length = 0;
	i = 0;
	length = find_node_pos(stack, &move, denominator, id);
	result = (char **)malloc((length + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[length] = NULL;
	while (i < length)
	{
		result[i] = ft_strdup(move);
		i++;
	}
	if (ft_strcmp(denominator, "a") == 0)
		result = ft_add_tab(result, "pb");
	return (result);
}

int		get_best_B_id(t_list **stack, int a_value)
{
	t_list	*iterator;
	int		biggest;
	int		best_value;
	int		best_id;

	if (!(*stack))
		return (0);
	biggest = INT_MIN;
	iterator = *stack;
	best_value = INT_MIN;
	best_id = (*stack)->id;
	while (iterator)
	{
		if (iterator->value < a_value && iterator->value > best_value)
		{
			best_value = iterator->value;
			best_id = iterator->id;
		}
		if (iterator->value > biggest)
			biggest = iterator->value;
		iterator = iterator->next;
	}
	if (best_value == INT_MIN)
		best_id = get_id(*stack, biggest);
	return (best_id);
}

char	**big_common_moves(char **moves_a, char **moves_b)
{
	char	**result;
	char	*move;
	int		length;
	int		i;

	i = 0;
	length = 0;
	if (!moves_b[0])
		return (ft_tabdup(moves_a));
	if (ft_strlen(moves_a[0]) != ft_strlen(moves_b[0]))
		return (ft_tabjoin(moves_b, moves_a));
	if (ft_strcmp(moves_a[0], "ra") == 0)
		move = ft_strdup("rr");
	else if (ft_strcmp(moves_a[0], "rra") == 0)
		move = ft_strdup("rrr");
	while (moves_a[length] && moves_b[length]
		&& ft_strlen(moves_a[length]) == ft_strlen(moves_b[length])
		&& ft_strcmp(moves_a[length], "pb") == 1)
		length++;
	if (length == 0)
		return (ft_tabjoin(moves_b, moves_a));
	moves_a = ft_erase(moves_a, 0, length);
	moves_b = ft_erase(moves_b, 0, length);
	result = (char **)malloc((length + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[length] = NULL;
	while (i < length)
	{
		result[i] = ft_strdup(move);
		i++;
	}
	if (moves_b[0])
		result = ft_tabjoin(result, moves_b);
	result = ft_tabjoin(result, moves_a);
	return (result);
}
