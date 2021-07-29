/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/26 17:59:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

void	big_manager(t_list **stack_a, t_list **stack_b)
{
	int		total_moves;
	char	**moves;

	total_moves = 0;
	while (*stack_a)
	{
		moves = big_moves_manager(stack_a, stack_b);
		execute_actions(stack_a, stack_b, moves);
		total_moves += ft_tablen((const char **)moves);
		ft_freetab(moves);
	}
	moves = tabjoin_free(calc_order_moves(stack_b),
			big_final_moves(stack_b), 3);
	total_moves += ft_tablen((const char **)moves);
	execute_actions(stack_a, stack_b, moves);
	if (check_order(stack_a) == 1)
		error_message();
	print_struct(*stack_a);
	ft_freetab(moves);
}
