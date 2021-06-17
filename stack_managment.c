/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:47:51 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 17:19:17 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(int *list, int len)
{
	t_list	*stack;
	t_list	*iterator;
	int		i;

	i = 0;
	stack = ft_lstnew(list[0]);
	i++;
	iterator = stack;
	while (i < len)
	{
		iterator->next = ft_lstnew(list[i]);
		iterator = iterator->next;
		i++;
	}
	return (stack);
}
