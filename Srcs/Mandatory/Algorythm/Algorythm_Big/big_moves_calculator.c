/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_moves_calculator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:44:04 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/29 18:18:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

char	**big_moves_manager(t_list **stack_a, t_list **stack_b)
{
	t_list	*iter;
	char	**best_moves;
	char	**moves_a;
	char	**moves_b;
	char	**both_moves;

	iter = *stack_a;
	best_moves = NULL;
	while (iter)
	{
		moves_b = moves_stack(stack_b, best_B_id(stack_b, iter->value), "b");
		moves_a = moves_stack(stack_a, iter->id, "a");
		both_moves = big_common_moves(moves_a, moves_b);
		if (!best_moves || ft_tablen((const char **)both_moves)
			< ft_tablen((const char **)best_moves))
		{
			ft_freetab(best_moves);
			best_moves = ft_tabdup(both_moves);
		}
		free_both_moves(moves_a, moves_b);
		ft_freetab(both_moves);
		iter = iter->next;
	}
	return (best_moves);
}

char	**moves_stack(t_list **stack, int id, char *denominator)
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
	free(move);
	return (result);
}

int	best_B_id(t_list **stack, int a_value)
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

char	**big_common_moves(char **a, char **b)
{
	char	**result;
	char	*move;
	int		length;

	length = 0;
	move = NULL;
	if (!b[0])
		return (ft_tabdup(a));
	while (a[length] && b[length] && ft_strcmp(a[length], "pb") == 1
		&& ft_strlen(a[length]) == ft_strlen(b[length]))
		length++;
	if (length == 0 || ft_strlen(a[0]) != ft_strlen(b[0]))
		return (tabjoin_free(b, a, 0));
	if (ft_strcmp(a[0], "ra") == 0)
		move = ft_strdup("rr");
	else if (ft_strcmp(a[0], "rra") == 0)
		move = ft_strdup("rrr");
	a = ft_erase(a, 0, length);
	b = ft_erase(b, 0, length);
	result = fill_moves(move, length);
	if (b[0])
		result = tabjoin_free(result, b, 1);
	result = tabjoin_free(result, a, 1);
	free_both_moves(a, b);
	return (result);
}
