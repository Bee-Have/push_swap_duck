/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_one_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:01:40 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/03 15:42:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*iterator;
	int		tmp;

	iterator = (*list);
	while (iterator->next->next != NULL)
		iterator = iterator->next;
	tmp = iterator->value;
	iterator->value = iterator->next->value;
	iterator->next->value = tmp;
	return ;
}

void	push(t_list **a, t_list **b)
{
	
}
