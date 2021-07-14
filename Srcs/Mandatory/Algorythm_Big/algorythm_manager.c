/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/14 11:44:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/push_swap.h"

void	algorythm_manager(t_list **stack_a, t_list **stack_b)
{
	int		total_moves;
	char	**moves;

	total_moves = 0;
	//call linear search to move presorted values to "B"
	// print_both_lists(*stack_a, *stack_b);
	while (*stack_a)
	{
		//call moves calculator
		moves = moves_calculator_manager(stack_a, stack_b);
		//call the actions executor
		execute_actions(stack_a, stack_b, moves);
		total_moves += ft_strlen_2d((const char **)moves);
		//repeat until list a is empty
	}
	//call checker to verify if all values are sorted in "B"
	moves = ft_tabjoin(calc_order_moves(stack_b), calc_final_moves(stack_b));
	//call executor to put everything from "B" to "A"
	total_moves += ft_strlen_2d((const char **)moves);
	execute_actions(stack_a, stack_b, moves);
	if (check_order(stack_a) == 1)
	{
		error_message();
		return ;
	}
	// ft_putstr("Total Instructions\n");
	// ft_putnbr(total_moves);
	free(moves);
}


