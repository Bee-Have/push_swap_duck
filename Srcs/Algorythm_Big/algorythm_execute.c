/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:28:33 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/13 15:23:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	execute_actions(t_list **stack_a, t_list **stack_b, char **actions)
{
	int		i;

	i = 0;
	while (actions[i])
	{
		if (ft_memcmp(actions[i], "rr", ft_strlen(actions[i])) == 0)
			double_rotate(stack_a, stack_b);
		else if (ft_memcmp(actions[i], "rrr", ft_strlen(actions[i])) == 0)
			double_reverse_rotate(stack_a, stack_b);
		else if (ft_memcmp(actions[i], "ra", ft_strlen(actions[i])) == 0)
			rotate(stack_a);
		else if (ft_memcmp(actions[i], "rb", ft_strlen(actions[i])) == 0)
			rotate(stack_b);
		else if (ft_memcmp(actions[i], "rra", ft_strlen(actions[i])) == 0)
			reverse_rotate(stack_a);
		else if (ft_memcmp(actions[i], "rrb", ft_strlen(actions[i])) == 0)
			reverse_rotate(stack_b);
		else if (ft_memcmp(actions[i], "pb", ft_strlen(actions[i])) == 0)
			push(stack_b, stack_a);
		else if (ft_memcmp(actions[i], "pa", ft_strlen(actions[i])) == 0)
			push(stack_a, stack_b);
		ft_putstr(actions[i]);
		write(1, "\n", 1);
		i++;
	}
	//debug
	// printf("output of actions:\n");
	// print_both_lists(*stack_a, *stack_b);
}