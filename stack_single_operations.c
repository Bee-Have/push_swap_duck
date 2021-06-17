/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_single_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:01:40 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 10:47:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*iterator;
	int		tmp;

	iterator = (*list);
	tmp = iterator->content;
	iterator->content = iterator->next->content;
	iterator->next->content = tmp;
	return ;
}

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp_src;

	tmp_src = *src;
	*src = (*src)->next;
	if (!dst)
	{
		*dst = tmp_src;
		(*dst)->next = NULL;
	}
	else
		ft_lstadd_front(dst, tmp_src);
}

void	rotate(t_list **stack)
{
	t_list	*last;

	if (!(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	stack = &(*stack)->next;
	last->next->next = NULL;
}
