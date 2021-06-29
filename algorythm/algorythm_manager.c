/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:31:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/29 12:29:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algorythm_manager(t_list **stack_a, t_list **stack_b)
{
	int		best_id;
	char	**actions;

	best_id = 0;
	//check list for values that are already sorted
	
	//verify number of moves for each number
	actions = check_moves_amount(stack_a, stack_b, &best_id);
	if (best_id == -1)
	{
		printf("bro your algo failed to find perfect number]n");
		exit(1);
	}
	//proceed with algorythm on specific stack node
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
		actions = node_actions_index(stack_a, stack_b, iterator->id)
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