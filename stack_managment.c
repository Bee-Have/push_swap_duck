/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:47:51 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/15 12:13:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(int *list, int len)
{
	t_list	*stack;
	t_list	*iterator;
	int		i;

	i = 0;
	if (!list)
	{
		stack = ft_lstnew(0);
		stack->null = 1;
	}
	else
		stack = ft_lstnew(list[0]);
	stack->index = 0;
	i++;
	iterator = stack;
	while (i <= len)
	{
		if (!list)
		{
			iterator->next = ft_lstnew(0);
			iterator->next->null = 1;
		}
		else
			iterator->next = ft_lstnew(list[i]);
		iterator->index = i;
		iterator = iterator->next;
		i++;
	}
	return (stack);
}
