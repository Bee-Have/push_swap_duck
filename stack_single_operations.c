/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_single_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:01:40 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/16 15:53:55 by amarini-         ###   ########.fr       */
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
	t_list	*tmp_dst;
	t_list	*tmp_src;

	tmp_dst = (*dst);
	tmp_src = (*src);
	// print_list((*src), (*dst));
	while (tmp_src->next && tmp_src->null == 1)
		tmp_src = tmp_src->next;
	while (tmp_dst->next && tmp_dst->null == 0)
		tmp_dst = tmp_dst->next;
	tmp_dst->content = tmp_src->content;
	// print_list((*src), (*dst));
	tmp_dst->null = 0;
	tmp_src->content = 0;
	tmp_src->null = 1;
}

void	rotate(t_list **stack)
{
	(void)stack;
}
