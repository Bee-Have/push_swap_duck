/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_moves_calculator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:44:04 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/12 19:13:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

char	**moves_calculator_manager(t_list **stack_a, t_list **stack_b)
{
	t_list	*iterator;
	char	**best_moves;
	char	**moves_a;
	char	**moves_b;
	char	**both_moves;

	iterator = *stack_a;
	best_moves = NULL;
	//iterate through "A"
	while (iterator->next)
	{
		//call function to have moves of "B"
		moves_b = calc_moves_stack(stack_b
				, get_best_B_id(stack_b, iterator->value), "b");
		//call function to have moves of "A"
		moves_a = calc_moves_stack(stack_a, iterator->id, "a");
		// ft_print_tab(moves_a);
		// ft_print_tab(moves_b);
		//call function to merge both moves (and check for 'rr' 'rrr')
		both_moves = check_common_moves(moves_a, moves_b);
		//check if size of it is smaller then best amount of moves
		if (!best_moves || ft_strlen_2d((const char **)both_moves)
			< ft_strlen_2d((const char **)best_moves))
			best_moves = both_moves;
		free(moves_a);
		free(moves_b);
		//else keep repeat
		iterator = iterator->next;
	}
	return (best_moves);
}

char	**calc_moves_stack(t_list **stack, int id, char *denominator)
{
	char	**result;
	char	*move;
	int		length;
	int		i;

	//if stack is NULL return empty char **
	if (!(*stack))
		return (ft_make_tab(NULL));
	length = 0;
	i = 0;
	//if node is in head
	//define number of times to add 'r'
	//if node is in tail
	//define number of times to add 'rr'
	if (id <= (lst_len(stack) / 2))
	{
		length = id;
		move = ft_strjoin("r", denominator);
	}
	else if (id >= (lst_len(stack) / 2))
	{
		length = lst_len(stack) - id;
		move = ft_strjoin("rr", denominator);
	}
	//malloc {char **} with defined number
	result = (char **)malloc((length + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	//set last to NULL
	result[length] = NULL;
	//for each defined number :
	while (i < length)
	{
		//add 'r' || 'rr' + the denominator
		result[i] = ft_strdup(move);
		i++;
	}
	//if the denominator is 'a', add 'pb'
	if (ft_strcmp(denominator, "a") == 0)
		result = ft_add_tab(result, "pb");
	//return {char **}
	return (result);
}

int		get_best_B_id(t_list **stack, int a_value)
{
	t_list	*iterator;
	int		best_value;
	int		best_id;

	if (!(*stack))
		return (0);
	iterator = *stack;
	best_value = (*stack)->value;
	best_id = (*stack)->id;
	while (iterator->next)
	{
		if (iterator->value < a_value && iterator->value > best_value)
		{
			best_value = iterator->value;
			best_id = iterator->id;
		}
		iterator = iterator->next;
	}
	return (best_id);
}

char	**check_common_moves(char **moves_a, char **moves_b)
{
	char	**result;
	char	*move;
	int		length;
	int		i;

	i = 0;
	length = 0;
	ft_print_tab(moves_a);
	if (!moves_b[0])
		return (ft_tabdup(moves_a));
	//check if first of both are the same
	//if not return join of "B"-"A"
	if (ft_strlen(moves_a[0]) != ft_strlen(moves_b[0]))
		return (ft_strjoin_2d(moves_b, moves_a));
	//if the same 'ra'='rb' - set new move to 'rr'
	//if the same 'rra'='rrb' - set new move to 'rrr'
	if (ft_strcmp(moves_a[0], "ra") == 0)
		move = ft_strdup("rr");
	else if (ft_strcmp(moves_a[0], "rra") == 0)
		move = ft_strdup("rrr");
	//count number of time they are the same
	while (ft_strlen(moves_a[length]) == ft_strlen(moves_b[length]))
		length++;
	moves_a = ft_erase(moves_a, 0, length);
	moves_b = ft_erase(moves_b, 0, length);
	//add size of moves_a to size && size of moves_b to size
	length += ft_strlen_2d((const char **)moves_b)
			+ ft_strlen_2d((const char **)moves_a);
	//malloc new {char **} with final size
	result = (char **)malloc((length + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	//set final to NULL
	result[length] = NULL;
	//while i < size :
	while (i < length)
	{
		//add 'rr' || 'rrr'
		result[i] = ft_strdup(move);
		i++;
	}
	//then add "B"
	result = ft_strjoin_2d(result, moves_b);
	//then add "A"
	result = ft_strjoin_2d(result, moves_a);
	//return {char **}
	return (result);
}
