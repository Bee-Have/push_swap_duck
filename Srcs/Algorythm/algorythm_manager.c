/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/29 14:21:49 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	algorythm_manager(t_list **stack_a, t_list **stack_b)
{
	int		best_id;
	int		i;
	char	**actions;
	char	**final;

	best_id = 0;
	while (i < lst_len(stack_a))
	{
		final = ft_strjoin_2d(final, "pa");
		i++;
	}
	//check list for values that are already sorted
	
	//verify number of moves for each number
	while (*stack_a)
	{
		actions = check_moves_amount(stack_a, stack_b, &best_id);
		if (best_id == -1)
		{
			printf("bro your algo failed to find the perfect threshold\n");
			exit(1);
		}
		//proceed with algorythm on specific stack node
		execute_actions(stack_a, stack_b, actions);
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
		actions = node_actions_index(stack_a, stack_b, iterator->id);
		if (ft_strlen_2d(actions) < ideal)
		{
			(*best_id) = iterator->id;
			return (actions);
		}
		iterator = iterator->next;
	}
	(*best_id) = -1;
	return (NULL);
}