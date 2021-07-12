/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/12 19:14:55 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	algorythm_manager(t_list **stack_a, t_list **stack_b)
{
	char	**moves;

	//call linear search to move presorted values to "B"
	print_both_lists(*stack_a, *stack_b);
	while (*stack_a)
	{
		//call moves calculator
		moves = moves_calculator_manager(stack_a, stack_b);
		//call the actions executor
		execute_actions(stack_a, stack_b, moves);
		//repeat until list a is empty
	}
	free(moves);
	//put all nodes in order in "B" (from greatest to smallest)
	//call checker to verify if all values are sorted in "B"

	//call executor to put everything from "B" to "A"
	print_both_lists(*stack_a, *stack_b);
}
