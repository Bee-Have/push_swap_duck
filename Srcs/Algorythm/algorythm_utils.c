/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:47:20 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/29 19:22:54 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

char	**node_moves_index(t_list **stack_a, t_list **stack_b, int id)
{
	t_list *iterator;
	char	**result;
	char	**moves_a;
	char	**moves_b;
	int		id_b;

	iterator = *stack_b;
	result = NULL;
	moves_a = NULL;
	moves_b = NULL;
	moves_a = stack_moves_register(stack_a, id, "a");
	moves_a = ft_add_tab(moves_a, "pb");
	if (!(*stack_b))
	{
		printf("HELL NAH\n");
		moves_b = ft_make_tab(NULL);
		id_b = 0;
	}
	else
	{
		while (stack_b && iterator->next
			&& iterator->content != get_node_value(stack_a, id))
			iterator = iterator->next;
		id_b = iterator->id;
		moves_b = stack_moves_register(stack_b, id_b, "b");
	}
	result = check_for_common_moves(moves_a, moves_b);
	return (result);
}

char	**stack_moves_register(t_list **stack, int id, char *s_name)
{
	char	*result;
	char	*moves;
	int		length;
	int		i;

	i = 0;
	if (id < (lst_len(stack) / 2))
	{
		moves = ft_strjoin("r", s_name);
		length = (id * ft_strlen(moves));
	}
	else
	{
		moves = ft_strjoin("rr", s_name);
		length = (lst_len(stack) - id) * ft_strlen(moves);
	}
	moves = ft_strjoin(moves, " ");
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (i < length)
	{
		result = ft_strjoin(result, moves);
		i++;
	}
	if (!stack && length == 0)
		return (NULL);
	return (ft_split(result, ' '));
}

char	**check_for_common_moves(char **moves_a, char **moves_b)
{
	char	**final;
	char	*moves;
	int		occurences;
	int		i;

	occurences = 0;
	i = 0;
	final = NULL;
	if (!moves_a[0])
		return (moves_b);
	else if (!moves_b[0])
		return (moves_a);
	while (ft_strlen(moves_a[0]) == ft_strlen(moves_b[0]))
		occurences++;
	if (occurences > 0 && moves_a[0][1] == 'a')
		moves = ft_strdup("rr");
	else if (occurences > 0 && moves_a[0][2] == 'a')
		moves = ft_strdup("rrr");
	moves_a = ft_erase(moves_a, 0, occurences);
	moves_b = ft_erase(moves_b, 0, occurences);
	while (i < occurences)
	{
		final = ft_add_tab(final, moves);
		i++;
	}
	if (moves_a)
		final = ft_strjoin_2d(final, moves_a);
	if (moves_b)
		final = ft_strjoin_2d(final, moves_b);
	return (final);
}