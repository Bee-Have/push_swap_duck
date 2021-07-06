/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/06 20:20:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	algorythm_manager(t_list **stack_a, t_list **stack_b)
{
	t_list	*iterator;
	int		best_id;
	char	**actions;
	char	**final;

	best_id = 0;
	iterator = *stack_a;
	final = NULL;
	while (iterator->next)
	{
		final = ft_add_tab(final, "ra");
		iterator = iterator->next;
	}
	//check list for values that are already sorted
	
	//verify number of moves for each number
	while (*stack_a)
	{
		actions = check_moves_amount(stack_a, stack_b, &best_id);
		if (best_id == -1 || !actions)
		{
			printf("bro your algo failed to find the perfect threshold\n");
			exit(1);
		}
		//proceed with algorythm on specific stack node
		printf("TEST\n.\n.");
		ft_print_tab(actions);
		printf(".\nTEST\n");
		execute_actions(stack_a, stack_b, actions);
		free(actions);
		// print_both_id(*stack_a, *stack_b);
	}
	execute_actions(stack_a, stack_b, final);
	return ;
}

char	**check_moves_amount(t_list **stack_a, t_list **stack_b, int *best_id)
{
	t_list	*iterator;
	// will have to re-make ideal number of moves because i'm not sure
	int		ideal;
	char	**actions;

	ideal = lst_len(stack_a);
	iterator = *stack_a;
	while (iterator->next)
	{
		actions = node_moves_index(stack_a, stack_b, iterator->id);
		if (ft_strlen_2d((const char **)actions) < ideal)
		{
			(*best_id) = iterator->id;
			return (actions);
		}
		iterator = iterator->next;
	}
	*best_id = -1;
	return (NULL);
}