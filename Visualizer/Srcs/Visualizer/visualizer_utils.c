/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:07:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/26 15:43:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap_visualizer.h"

void	rescale_values(t_win_info *win, t_list **stack_a, t_list **stack_b)
{
	t_list		*i;

	i = NULL;
	if (stack_a)
		stack_values_change(stack_a, win);
	if (stack_b)
		stack_values_change(stack_b, win);
	return ;
}

void	stack_values_change(t_list **stack, t_win_info *win)
{
	t_list			*iter;
	long long int	tmp;

	iter = *stack;
	tmp = 0;
	// printf("smallest-[%d] biggest-[%d]\n", smallest, biggest);
	while (iter)
	{
		if (iter->value != win->max && iter->value != win->min)
		{
			tmp = (win->height * (iter->value - 1)) / ((win->height - 1) - 1);
			iter->value = tmp;
		}
		iter = iter->next;
	}
	return ;
}

int		check_order(t_list **stack)
{
	t_list	*iterator;

	if (!stack)
		return (1);
	iterator = *stack;
	while (iterator->next)
	{
		if (iterator->value > iterator->next->value)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}
