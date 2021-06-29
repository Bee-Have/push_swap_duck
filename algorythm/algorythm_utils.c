/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:47:20 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/29 12:19:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	node_moves_index(t_list **stack_a, t_list **stack_b, int id)
{
	t_list *iterator;
	char	**result;
	char	**moves_a;
	char	**moves_b;
	int		id_b;
	int		i;

	iterator = *stack_b;
	moves_a = stack_moves_register(stack_a, id, "a");
	while (iterator->next && iterator->content != get_node_value(stack_a, id))
		iterator = iterator->next;
	id_b = iterator->id;
	moves_b = stack_moves_register(stack_b, id_b, "b");
	result = check_for_common_moves(moves_a, moves_b);
	return (result);
}

char	**stack_moves_register(t_list **stack, int id, char *s_name)
{
	char	*result;
	char	*move;
	int		length;
	int		i;

	i = 0;
	if (id < (lst_len(stack) / 2))
	{
		move = ft_strjoin("r", s_name);
		length = (id * ft_strlen(move));
	}
	else
	{
		move = ft_strjoin("rr", s_name);
		length = (lst_len(stack) - id) * ft_strlen(move);
	}
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < length)
	{
		result = ft_strjoin(result, move);
		i += ft_strlen(move);
	}
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
	while (ft_strlen(moves_a[0]) == ft_strlen(moves_b[0]))
		occurences++;
	if (occurences > 0 && moves_a[0][1] == 'a')
		moves = ft_strdup("rr");
	else if (occurences > 0 && moves_a[0][2] == 'a')
		moves = ft_strdup("rrr");
	moves_a = ft_strtrim_2d(moves_a, occurences);
	moves_b = ft_strtrim_2d(moves_b, occurences);
	while (i < occurences)
	{
		final = ft_strjoin_2d(final, moves);
		i++;
	}
	if (moves_a)
		final = ft_strjoin_2d(final, moves_a);
	if (moves_b)
		final = ft_strjoin_2d(final, moves_b);
	return (final);
}
