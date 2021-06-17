/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:14:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/06/17 10:45:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
	return ;
}

void	print_both_lists(t_list *stack_a, t_list *stack_b)
{
	while (stack_a)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\n");
	while (stack_b)
	{
		printf("%d ", stack_b->content);
		stack_b = stack_b->next;
	}
	printf("\n\n");
	return ;
}
