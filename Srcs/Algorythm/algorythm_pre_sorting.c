/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_pre_sorting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:42:04 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/12 15:27:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

//global function to pre-sort
void	pre_sorting_manager(t_list **stack_a, t_list **stack_b)
{
	t_list	*iterator;
	int		threshold;
	char	**moves;

	iterator = *stack_a;
	//define threshold of acceptance
	threshold = acceptable_sorted_id_threshold(stack_a);
	//iterate through stack
	while (iterator->next)
	{
		//call function to check if id is in perfect place more or less
		//change it to sorted if good
		if (check_id_placement(stack_a, iterator->id, threshold) == 1)
			iterator->sorted = 1;
		//repeat
		iterator = iterator->next;
	}
	//call function to put everything from "A" to "B"
	moves = transfer_sorted_nodes(stack_a);
	execute_actions(stack_a, stack_b, moves);
}

//function to check if id is in right place
int	check_id_placement(t_list **stack, int id, int threshold)
{
	t_list	*iterator;
	int		perfect;
	int		test_id;

	iterator = *stack;
	while (iterator->next && iterator->id != id)
		iterator = iterator->next;
	//calculate perfect id
	perfect = iterator->id % lst_len(stack);
	test_id = perfect - threshold;
	//if value has perfect id return 1
	if (iterator->id == perfect)
		return (1);
	//if value id '+' || '-' threshold is perfect value
	// && there are no 'sorted' nodes of higher values in lesser ids then him
	if (iterator->id >= (perfect - threshold)
			&& iterator->value <= (perfect + threshold))
		while (test_id <= (perfect + threshold))
		{
			if (get_node_sorted_value(stack, test_id) == 1)
			{
				if (test_id < id
					&& get_node_value(stack, test_id) > iterator->value)
					return (0);
				else if (test_id > id
						&& get_node_value(stack, test_id) < iterator->value)
					return (0);
			}
			test_id++;
		}
	return (1);
}

//function to decide the excepted amount of values for perfet id
int		acceptable_sorted_id_threshold(t_list **stack_a)
{
	int		threshold;
	int		stack_size;

	threshold = 0;
	//determine size of the stack
	stack_size = lst_len(stack_a);
	//if size <= 10 | threshold = 2
	if (stack_size <= 10)
		threshold = 2;
	//else if size <= 100 | threshold = 5
	else if (stack_size <= 100)
		threshold = 5;
	//else if size <= 1000 | threshold = 10
	else if (stack_size <= 1000)
		threshold = 10;
	//else | threshold = 20
	else
		threshold = 20;
	if (threshold == 0)
		ft_putstr("something fucked up with acceptable threshold for sorted ids\n");
	return (threshold);
}

//function to moves all sorted values in "B"
char	**transfer_sorted_nodes(t_list **stack_a)
{
	t_list	*iterator;
	char	**moves;

	moves = NULL;
	iterator = *stack_a;
	//iterate through "A"
	while (iterator->next)
	{
		//while no sorted is found | "ra"
		//if sorted found | "pb"
		if (iterator->sorted == 1)
			moves = ft_add_tab(moves, "pb");
		else
			moves = ft_add_tab(moves, "ra");
		//repreat until reaching end of "A"
		iterator = iterator->next;
	}
	return (moves);
}
