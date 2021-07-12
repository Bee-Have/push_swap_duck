/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/12 15:09:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	algorythm_manager(t_list **stack_a, t_list **stack_b)
{
	// char	**moves;

	//call linear search to move presorted values to "B"
	print_both_lists(*stack_a, *stack_b);
	pre_sorting_manager(stack_a, stack_b);
	print_both_lists(*stack_a, *stack_b);
	//call moves calculator

	//call the best actions executor
	
	//repeat until list a is empty

	//call checker to verify if all values are sorted in "B"

	//call executor to put everything from "B" to "A"
	
}
