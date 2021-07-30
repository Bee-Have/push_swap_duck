/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:28:33 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/30 16:42:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/push_swap.h"

void	execute_actions(t_list **stack_a, t_list **stack_b, char **actions)
{
	int		i;

	i = 0;
	while (actions[i])
	{
		actions_interpretor(actions[i], stack_a, stack_b);
		ft_putstr(actions[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	actions_interpretor(char *action, t_list **stack_a, t_list **stack_b)
{
	if (ft_memcmp(action, "rr", ft_strlen(action)) == 0)
		double_rotate(stack_a, stack_b);
	else if (ft_memcmp(action, "rrr", ft_strlen(action)) == 0)
		double_reverse_rotate(stack_a, stack_b);
	else if (ft_memcmp(action, "ra", ft_strlen(action)) == 0)
		rotate(stack_a);
	else if (ft_memcmp(action, "rb", ft_strlen(action)) == 0)
		rotate(stack_b);
	else if (ft_memcmp(action, "rra", ft_strlen(action)) == 0)
		reverse_rotate(stack_a);
	else if (ft_memcmp(action, "rrb", ft_strlen(action)) == 0)
		reverse_rotate(stack_b);
	else if (ft_memcmp(action, "pb", ft_strlen(action)) == 0)
		push(stack_b, stack_a);
	else if (ft_memcmp(action, "pa", ft_strlen(action)) == 0)
		push(stack_a, stack_b);
	else if (ft_memcmp(action, "sa", ft_strlen(action)) == 0)
		swap(stack_a);
	else if (ft_memcmp(action, "sb", ft_strlen(action)) == 0)
		swap(stack_b);
}
