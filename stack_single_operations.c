/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_single_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:01:40 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 17:16:46 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*iterator;
	int		tmp;

	if (!*stack)
		return ;
	iterator = (*stack);
	tmp = iterator->content;
	iterator->content = iterator->next->content;
	iterator->next->content = tmp;
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
	while (last->next)
		last = last->next;
	last->next = *stack;
	last = last->next;
	*stack = (*stack)->next;
	last->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (!(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}
