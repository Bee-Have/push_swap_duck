/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:47:51 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/03 15:50:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(int *list, int len)
{
	t_list	*stack;
	t_list	*iterator;
	int		i;

	i = len;
	if (!list)
		stack = ft_lstnew(0);
	else
		stack = ft_lstnew(ft_itoa(&list[i]));
	i--;
	iterator = stack;
	while (i >= 0)
	{
		if (!list)
			iterator->next = ft_lstnew(0);
		else
			iterator->next = ft_lstnew(ft_itoa(list[i]));
		iterator = iterator->next;
		i--;
	}
	return (stack);
}
