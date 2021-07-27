/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_single_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:01:40 by amarini-          #+#    #+#             */
/*   Updated: 2021/07/27 16:36:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*iterator;
	int		tmp;

	if (!*stack)
		return ;
	iterator = (*stack);
	tmp = iterator->value;
	iterator->value = iterator->next->value;
	(*stack)->id = 0;
	(*stack)->next->id = 1;
	iterator->next->value = tmp;
}

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp_src;

	tmp_src = *src;
	if (!*src)
		return ;
	if (!(*src)->next)
		*src = NULL;
	else
		*src = (*src)->next;
	if (!dst)
	{
		(*dst) = ft_lstnew((*src)->value);
		tmp_src->next = NULL;
	}
	else
		ft_lstadd_front(dst, tmp_src);
	place_id(src);
	place_id(dst);
}

void	rotate(t_list **stack)
{
	t_list	*last;

	if (!(*stack)->next || !(*stack))
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	last = last->next;
	*stack = (*stack)->next;
	last->next = NULL;
	place_id(stack);
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
	place_id(stack);
}
